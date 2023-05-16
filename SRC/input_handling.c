/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:50 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/16 14:17:37 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_handling(t_pipex *generate, int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_exit(generate, "input argument error\n");
	ft_bzero(generate, sizeof(*generate));
	generate->argc = argc;
	generate->argv = argv;
	generate->envp = envp;
	generate->infile = argv[1];
	generate->argv2 = argv[2];
	generate->argv3 = argv[3];
	generate->outfile = argv[4];
	generate->cmd1 = ft_split(generate->argv2, ' ');
	if (!generate->cmd1)
		error_exit(generate, "split cmd1 failed\n");
	generate->cmd2 = ft_split(generate->argv3, ' ');
	if (!generate->cmd2)
		error_exit(generate, "split cmd2 failed\n");
}
