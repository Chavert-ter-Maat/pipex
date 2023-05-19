/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 14:09:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/19 10:42:15 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	run_no_slash(t_pipex *generate, char *argv, char **cmd)
{
	size_t	index;
	size_t	lenght;

	index = 0;
	lenght = (ft_strlen(generate->path) + ft_strlen(argv) + 2);
	generate->access_path = ft_calloc(lenght, sizeof(char));
	if (!generate->access_path)
		error_exit(generate, "ft_calloc generate->access_path failed");
	while (generate->split_path[index])
	{
		ft_bzero(generate->access_path, lenght);
		ft_strlcat(generate->access_path, generate->split_path[index], lenght);
		ft_strlcat(generate->access_path, "/", lenght);
		ft_strlcat(generate->access_path, cmd[0], lenght);
		if (access(generate->access_path, F_OK | X_OK) == SUCCES)
			break ;
		index++;
	}
	if (access(generate->access_path, F_OK | X_OK) == FAILED)
		error_access(generate, argv);
	if (execve(generate->access_path, cmd, generate->envp) == FAILED)
		perror_exit(generate, "execve");
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
		error_exit(generate, "no path in envp found\n");
	return (&path[5]);
}

void	run_command(t_pipex *generate, char *argv, char **cmd)
{
	generate->path = get_path(generate);
	generate->split_path = ft_split(generate->path, ':');
	if (!generate->split_path)
		error_exit(generate, "ft_split split_path failed\n");
	if (ft_strchr(cmd[0], '/') == NOT_FOUND)
		run_no_slash(generate, argv, cmd);
	else
	{
		if (access(argv, F_OK | X_OK) == FAILED)
			perror_exit(generate, generate->argv3);
		if (execve(argv, cmd, generate->envp) == FAILED)
			perror_exit(generate, "execve");
	}
}
