/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:09:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/25 17:27:22 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// execve is not protected!
// while loop doesnt work
static void	run_access_path(t_pipex *generate, char **split_path)
{
	size_t	index_path;
	size_t	path_length;
	char	*path;
	
	index_path = 0;
	path_length = (ft_strlen(generate->path) + ft_strlen(generate->argv[2]) + 1);
	path = malloc(path_length * sizeof(char));
	if (!path)
		error("malloc path failed");
	path[0] = '\0';
	while (split_path[index_path])
	{
		ft_printf("hey");
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			break ;
		ft_strlcat(path, split_path[index_path], path_length);
		ft_strlcat(path, "/", path_length);
		ft_strlcat(path, split_path[index_path + 1], path_length);
		index_path++;
	}
	ft_printf("%s", path);
	execve(path, &generate->argv[2], generate->envp);
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

// check split path
void	run_command(t_pipex *generate)
{
	char	**split_path;
	
	generate->path = get_path(generate);
	split_path = ft_split(generate->path, ':');
	if (!split_path)
		error("split_path failed");
	run_access_path(generate, split_path);
	free(split_path);
}