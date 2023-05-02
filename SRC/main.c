/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/02 17:10:34 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	execute_child_1(t_pipex *generate)
{
	int infile_fd;

	if (close(generate->pipe_fd[PIPE_READ_END]) == FAILED)
		error("close() failed");
	infile_fd = open(generate->infile, O_RDONLY);
	if (infile_fd == FAILED)
		error("open() failed");
	if (dup2(infile_fd, STDIN_FILENO) == FAILED)
		error("dup2() failed");
	ft_putendl_fd("test 2", 0);
	if (dup2(generate->pipe_fd[PIPE_WRITE_END], STDOUT_FILENO) == FAILED)
		error("dup2() failed");
	ft_putendl_fd("test 3", 0);
	run_command(generate, generate->argv2, generate->cmd1);
	if (close(infile_fd) == FAILED)
		error("close() failed");
		
	
}

static void execute_child_2(t_pipex *generate)
{
	int fd_outfile;

	fd_outfile = open(generate->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_outfile == FAILED)
		error("open() outfile failed");
	if (dup2(generate->pipe_fd[PIPE_READ_END], STDIN_FILENO) == FAILED)
		error("dup2() failed");
	if (close(generate->pipe_fd[PIPE_READ_END]) == FAILED)
		error("close() failed");
	if (dup2(fd_outfile, STDOUT_FILENO) == FAILED)
		error("dup2() failed");
	run_command(generate, generate->argv3, generate->cmd2);
	if (close(fd_outfile) == FAILED)
		error("close() failed");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex generate;
	pid_t child_pid_1;
	pid_t child_pid_2;

	if (argc != 5)
		error("input argument error");
	initialize(&generate, argc, argv, envp);
	if (pipe(generate.pipe_fd) == FAILED)
		error("pipe() failed");
	child_pid_1 = fork();
	if (child_pid_1 == FAILED)
		error("fork 1 failed");
	if (child_pid_1 == SUCCES)
		execute_child_1(&generate);
	child_pid_2 = fork();
	if (child_pid_2 == FAILED)
		error("fork 2 failed\n");
	if (child_pid_2 == SUCCES)
		execute_child_2(&generate);
	close(generate.pipe_fd[PIPE_READ_END]);
	close(generate.pipe_fd[PIPE_WRITE_END]);
	waitpid(child_pid_1, NULL, 0);
	waitpid(child_pid_2, NULL, 0);
	ft_putendl_fd("parent proces", STDERR_FILENO);
	exit(EXIT_SUCCESS);
}
