/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:50 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/22 11:06:40 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	split_commands(t_pipex *generate)
{
	generate->cmd1 = ft_split(generate->argv2, ' ');
		if (!generate->cmd1)
		error_exit(generate, "split cmd1 failed\n");
	generate->cmd2 = ft_split(generate->argv3, ' ');
		if (!generate->cmd2)
		error_exit(generate, "split cmd2 failed\n");
}

void	input_handling(t_pipex *generate, int argc, char **argv, char **envp)
{
	if (argc != 5)
		input_error();
	generate->envp = envp;
	generate->infile = argv[1];
	if(!generate->infile || ft_strlen(generate->infile) == 0)
		input_error();
	generate->argv2 = argv[2];
	if(!generate->argv2 || ft_strlen(generate->argv2) == 0)
		input_error();
	generate->argv3 = argv[3];
	if(!generate->argv3 || ft_strlen(generate->argv3) == 0)
		input_error();
	generate->outfile = argv[4];
	if(!generate->outfile || ft_strlen(generate->outfile) == 0)
		input_error();
	split_commands(generate);
}
