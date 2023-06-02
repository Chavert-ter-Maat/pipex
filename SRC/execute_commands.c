/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:09:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/06/02 13:41:42 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*run_no_slash(t_pipex *generate, char **cmd)
{
	size_t	index;
	char	*tmp_path;
	char	*cmd_slash;

	if (generate->split_path == NULL)
		return (cmd[0]);
	cmd_slash = ft_strjoin("/", cmd[0]);
	index = 0;
	while (generate->split_path[index])
	{
		tmp_path = ft_strjoin(generate->split_path[index], cmd_slash);
		if (access(tmp_path, F_OK | X_OK) == SUCCES)
			break ;
		free(tmp_path);
		index++;
	}
	free(cmd_slash);
	if (generate->split_path[index] == NULL)
		return (cmd[0]);
	return (tmp_path);
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
		return (NULL);
	return (&path[5]);
}

void	run_command(t_pipex *generate, char *argv, char **cmd)
{
	char	*cmd_path;

	cmd_path = NULL;
	generate->path = get_path(generate);
	generate->split_path = ft_split(generate->path, ':');
	if (cmd[0] && (ft_strncmp(cmd[0], "/", 1) || ft_strncmp(cmd[0], "./", 2)))
	{
		cmd_path = run_no_slash(generate, cmd);
		if (execve(cmd_path, cmd, generate->envp) == FAILED)
			error_no_command(argv);
	}
	if (execve(cmd[0], cmd, generate->envp) == FAILED)
		error_no_command(argv);
}
