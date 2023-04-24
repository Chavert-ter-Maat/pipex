/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:03 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/24 16:44:09 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	infile(t_pipex *generate)
{
	int fd = open(generate->argv[1], O_RDONLY);
	if (fd == -1) 
	{
		ft_printf("open() failed\n");
		perror("open");
		exit(EXIT_FAILURE);
	}
	// run_command();
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	generate;
	
	if (argc != 5)
	{	
		ft_printf("input argument error");
		exit(EXIT_FAILURE);
	}
	initialize(&generate, argc, argv, envp);
	infile(&generate);
	exit(EXIT_SUCCESS);
}
