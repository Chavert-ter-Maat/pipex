/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/01 16:54:13 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	child_1(t_pipex *generate)
{
	int infile_fd;

	close(generate->pipe_fd[PIPE_READ_END]);
	infile_fd = open(generate->argv[1], O_RDONLY);
	if (infile_fd == FAILED) 
		error("open() failed");
	if (dup2(infile_fd, STDIN_FILENO) == FAILED)
		error("dup2() failed");
	// if (dup2(generate->pipe_fd[PIPE_WRITE_END], STDOUT_FILENO) == FAILED)
	// 	error("dup2() failed");
	run_command(generate);
	close(infile_fd);
}

// static void child_2(t_pipex *generate)
// {
// 	int fd_outfile;

// 	close(generate->pipe_fd[PIPE_READ_END]);
// 	fd_outfile = open(generate->argv[3], O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (fd_outfile == FAILED)
// 		error("open() outfile failed");
// 	if (dup2(fd_outfile, STDOUT_FILENO) == FAILED)
// 		error("dup2() failed");
// 	run_command(generate);
// 	close(fd_outfile);
// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex generate;
	pid_t child_pid_1;
	// pid_t child_pid_2;

	// if (argc != 4)
	if (argc != 3)
		error("input argument error");
	initialize(&generate, argc, argv, envp);
	if (pipe(generate.pipe_fd) == FAILED)
		error("pipe() failed");
	child_pid_1 = fork();
	if (child_pid_1 == FAILED)
		error("fork 1 failed");
	if (child_pid_1 == 0)
		child_1(&generate);
	// child_pid_2 = fork();
	// if (child_pid_2 == FAILED)
	// 	error("fork 2 failed\n");
	// if (child_pid_2 == 0)
	// 	child_2(&generate);
	close(generate.pipe_fd[0]);
	close(generate.pipe_fd[1]);
	waitpid(child_pid_1, NULL, 0);
	// waitpid(child_pid_2, NULL, 0);
	exit(EXIT_SUCCESS);
}
