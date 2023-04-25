/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/25 16:03:25 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	child_1(t_pipex *generate)
{
	int	infile_fd;
	infile_fd = open(generate->argv[1], O_RDONLY);
	if (infile_fd == -1) 
		error("open() failed");
	run_command(generate);
	close(infile_fd);
}

// 1) error handling
// 2) initializes all variables
// 3) executes pipex function and saves status on variable status
// 4) returns status

int	main(int argc, char **argv, char **envp)
{
	t_pipex	generate;
	pid_t	child_pid_1;
	pid_t	child_pid_2;
	// int		pipe_fd[2];

	if (argc != 5)
		error("input argument error");
	initialize(&generate, argc, argv, envp);
	child_pid_1 = fork();
	if (child_pid_1 == -1)
		error("fork 1 failed");
	// printf("%d = pid1\n", child_pid_1);
	if (child_pid_1 == 0)
	{
		child_1(&generate);
		child_pid_2 = fork();
		if (child_pid_2 == -1)
			error("fork 2 failed");
		// printf("%d = pid2\n", child_pid_2);
		// if (child_pid_2 == 0)
		// 	child_2(&generate);
	}
	exit(EXIT_SUCCESS);
}
