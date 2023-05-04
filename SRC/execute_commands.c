/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:09:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/04 14:59:48 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_access_path(t_pipex *generate, char *argv)
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
	return (new_path);
}

void	run_command(t_pipex *generate, char *argv, char **cmd)
{
	char	*new_path;
	
	new_path = get_access_path(generate, argv);
	if (execve(new_path, cmd, generate->envp) == FAILED)
		error("execve failed");
	// free(generate->split_path);
}