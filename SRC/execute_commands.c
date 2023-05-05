/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:09:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/05 16:04:19 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	run_no_slash(t_pipex *generate, char *argv, char **cmd)
{
	size_t	index_path;
	size_t	path_len;
	char	*access_cmd_path;

	index_path = 0;
	path_len = (ft_strlen(generate->path) + ft_strlen(argv) + 2);
	access_cmd_path = ft_calloc(path_len * sizeof(char), path_len);
	if (!access_cmd_path)
		error("ft_calloc() access_cmd_path failed");
	while (generate->split_path[index_path])
	{
		ft_bzero(access_cmd_path, path_len);
		ft_strlcat(access_cmd_path, generate->split_path[index_path], path_len);
		ft_strlcat(access_cmd_path, "/", path_len);
		ft_strlcat(access_cmd_path, cmd[0], path_len);
		if (access(access_cmd_path, F_OK | X_OK) == SUCCES)
			break ;
		index_path++;
	}
	if (execve(access_cmd_path, cmd, generate->envp) == FAILED)
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
		error("no path in envp found\n");
	return (&path[5]);
}

void	run_command(t_pipex *generate, char *argv, char **cmd)
{
	generate->path = get_path(generate);
	generate->split_path = ft_split(generate->path, ':');
	if (!generate->split_path)
		error("split_path failed\n");
	if (ft_strchr(cmd[0], '/') == NULL)
		run_no_slash(generate, argv, cmd);
	else
	{
		if (access(argv, F_OK | X_OK) == FAILED)
			error("command path error");
		execve(argv, cmd, generate->envp);
	}
}
