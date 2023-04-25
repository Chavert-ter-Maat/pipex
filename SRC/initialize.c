/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:50 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/25 17:16:08 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	initialize(t_pipex *generate, int argc, char **argv, char **envp)
{
	ft_bzero(generate, sizeof(*generate));
	generate->argc = argc;
	generate->argv = argv;
	generate->envp = envp;
}

// void	print_envp(t_pipex *generate)
// {
// 	int i;

// 	i = 0;
// 	while(generate->envp[i])
// 	{
// 		ft_printf("%s\n", generate->envp[i]);
// 		i++;
// 	}
// }