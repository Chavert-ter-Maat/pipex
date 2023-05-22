/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/22 11:06:47 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	close_and_wait(t_pipex *generate)
{
	int	status;

	if (waitpid(generate->child_pid_1, NULL, 0) == FAILED)
		perror_exit(generate, "waitpid");
	if (waitpid(generate->child_pid_2, &status, 0) == FAILED)
		perror_exit(generate, "waitpid");
	if (close(generate->pipe_fd[PIPE_READ_END]) == FAILED)
		perror_exit(generate, "close");
	if (close(generate->pipe_fd[PIPE_WRITE_END]) == FAILED)
		perror_exit(generate, "close");
	return (status);
}

static void	execute_child_2(t_pipex *generate)
{
	if (close(generate->pipe_fd[PIPE_WRITE_END]) == FAILED)
		perror_exit(generate, "close");
	generate->outfile_fd = open(generate->outfile, O_CREAT
			| O_WRONLY | O_TRUNC, 0644);
	if (generate->outfile_fd == FAILED)
		perror_exit(generate, generate->outfile);
	if (dup2(generate->outfile_fd, STDOUT_FILENO) == FAILED)
		perror_exit(generate, "dup2");
	if (dup2(generate->pipe_fd[PIPE_READ_END], STDIN_FILENO) == FAILED)
		perror_exit(generate, "dup2");
	run_command(generate, generate->argv3, generate->cmd2);
	if (close(generate->outfile_fd) == FAILED)
		perror_exit(generate, "close");
}

static void	execute_child_1(t_pipex *generate)
{
	if (close(generate->pipe_fd[PIPE_READ_END]) == FAILED)
		perror_exit(generate, "close");
	generate->infile_fd = open(generate->infile, O_RDONLY);
	if (generate->infile_fd == FAILED)
		perror_exit(generate, generate->infile);
	if (dup2(generate->pipe_fd[PIPE_WRITE_END], STDOUT_FILENO) == FAILED)
		perror_exit(generate, "dup2");
	if (dup2(generate->infile_fd, STDIN_FILENO) == FAILED)
		perror_exit(generate, "dup2");
	run_command(generate, generate->argv2, generate->cmd1);
	if (close(generate->infile_fd) == FAILED)
		perror_exit(generate, "close");
}

static void	generate_pipe_forks(t_pipex *generate)
{
	if (pipe(generate->pipe_fd) == FAILED)
		perror_exit(generate, "pipe");
	generate->child_pid_1 = fork();
	if (generate->child_pid_1 == FAILED)
		perror_exit(generate, "fork");
	if (generate->child_pid_1 == SUCCES)
		execute_child_1(generate);
	generate->child_pid_2 = fork();
	if (generate->child_pid_2 == FAILED)
		perror_exit(generate, "fork");
	if (generate->child_pid_2 == SUCCES)
		execute_child_2(generate);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*generate;
	int		status;

	generate = ft_calloc(1, sizeof(t_pipex));
	if (!generate)
		exit(EXIT_FAILURE);
	input_handling(generate, argc, argv, envp);
	generate_pipe_forks(generate);
	status = close_and_wait(generate);
	wait(&status);
	free_before_exit(&generate);
	free(generate);
	exit(WEXITSTATUS(status));
}
