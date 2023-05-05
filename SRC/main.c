/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/05 16:05:13 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	execute_child_1(t_pipex *generate)
{
	int	infile_fd;

	if (close(generate->pipe_fd[PIPE_READ_END]) == FAILED)
		error("close() failed\n");
	infile_fd = open(generate->infile, O_RDONLY);
	if (infile_fd == FAILED)
		error("open() failed\n");
	if (dup2(infile_fd, STDIN_FILENO) == FAILED)
		error("dup2() failed\n");
	if (dup2(generate->pipe_fd[PIPE_WRITE_END], STDOUT_FILENO) == FAILED)
		error("dup2() failed\n");
	run_command(generate, generate->argv2, generate->cmd1);
	if (close(infile_fd) == FAILED)
		error("close() failed\n");
}

static void	execute_child_2(t_pipex *generate)
{
	int	fd_outfile;

	if (close(generate->pipe_fd[PIPE_WRITE_END]) == FAILED)
		error("close() failed\n");
	fd_outfile = open(generate->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_outfile == FAILED)
		error("open() outfile failed\n");
	if (dup2(generate->pipe_fd[PIPE_READ_END], STDIN_FILENO) == FAILED)
		error("dup2() failed\n");
	if (dup2(fd_outfile, STDOUT_FILENO) == FAILED)
		error("dup2() failed\n");
	run_command(generate, generate->argv3, generate->cmd2);
	if (close(fd_outfile) == FAILED)
		error("close() failed\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	generate;
	int		status;

	input_parsing(&generate, argc, argv, envp);
	if (pipe(generate.pipe_fd) == FAILED)
		error("pipe() failed\n");
	generate.child_pid_1 = fork();
	if (generate.child_pid_1 == FAILED)
		error("fork 1 failed\n");
	if (generate.child_pid_1 == SUCCES)
		execute_child_1(&generate);
	generate.child_pid_2 = fork();
	if (generate.child_pid_2 == FAILED)
		error("fork 2 failed\n");
	if (generate.child_pid_2 == SUCCES)
		execute_child_2(&generate);
	if (close(generate.pipe_fd[PIPE_READ_END]) == FAILED)
		error("close failed");
	if (close(generate.pipe_fd[PIPE_WRITE_END]) == FAILED)
		error("close() failed\n");
	if (waitpid(generate.child_pid_1, NULL, 0) == FAILED)
		error("waitpid failed\n");
	if (waitpid(generate.child_pid_2, &status, 0) == FAILED)
		error("waitpid failed\n");
	exit(WEXITSTATUS(status));
}
