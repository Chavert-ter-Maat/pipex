/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:09:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/02 16:59:06 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	run_access_path(t_pipex *generate, char *argv, char **cmd)
{
	size_t	index_path;
	size_t	path_length;
	char	*new_path;
	
	index_path = 0;
	path_length = (ft_strlen(generate->path) + ft_strlen(argv) + 2);
	new_path = malloc(path_length * sizeof(char));
	if (!new_path)
		error("malloc new_path failed");
	new_path[0] = '\0';
	while (generate->split_path[index_path])
	{
		ft_bzero(new_path, path_length);
		ft_strlcat(new_path, generate->split_path[index_path], path_length);
		ft_strlcat(new_path, "/", path_length);
		ft_strlcat(new_path, argv, path_length);
		if (access(new_path, F_OK | X_OK) == 0)
			break ;
		index_path++;
	}
	if (execve(new_path, cmd, generate->envp) == FAILED)
		error("execve failed");
}

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
		error("no path in envp found");
	return (&path[5]);
}

void	run_command(t_pipex *generate, char *argv, char **cmd)
{
	generate->path = get_path(generate);
	generate->split_path = ft_split(generate->path, ':');
	if (!generate->split_path)
		error("split_path failed");
	run_access_path(generate, argv, cmd);
	free(generate->split_path);
}