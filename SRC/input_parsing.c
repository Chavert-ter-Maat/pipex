/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:50 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/04 14:59:54 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_path(t_pipex *generate)
{
	char	*path;
	size_t	index;

	index = 0;	
	while (generate->envp[index])
		{
			path = ft_strnstr(generate->envp[index], "PATH=", 5);
			if (path)
				break ;
			index++;
		}
	if (!path)
		error("no path in envp found\n");
	return (&path[5]);
}

static void	initialize_path(t_pipex *generate)
{
	generate->path = get_path(generate);
	generate->split_path = ft_split(generate->path, ':');
	if (!generate->split_path)
		error("split_path failed\n");
}


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
	if (!generate->cmd1)
		error("split cmd1 failed\n");
	generate->cmd2 = ft_split(generate->argv3, ' ');
	if (!generate->cmd2)
		error("split cmd2 failed\n");
	initialize_path(generate);
}
