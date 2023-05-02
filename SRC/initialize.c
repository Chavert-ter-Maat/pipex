/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:50 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/02 16:37:51 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	initialize(t_pipex *generate, int argc, char **argv, char **envp)
{
	ft_bzero(generate, sizeof(*generate));
	generate->argc = argc;
	generate->argv = argv;
	generate->envp = envp;
	generate->infile = argv[1];
	generate->argv2 = argv[2];
	generate->argv3 = argv[3];
	generate->outfile = argv[4];
	generate->cmd1 = ft_split(generate->argv2, ' ');
	generate->cmd2 = ft_split(generate->argv3, ' ');
}
