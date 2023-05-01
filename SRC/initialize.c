/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:50 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/01 16:33:14 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	initialize(t_pipex *generate, int argc, char **argv, char **envp)
{
	ft_bzero(generate, sizeof(*generate));
	generate->argc = argc;
	generate->argv = argv;
	generate->envp = envp;
	// generate->infile = argv[1];
	// generate->cmd1 = argv[2];
	// generate->cmd1 = argv[3];
	// generate->outfile = argv[4];
}
