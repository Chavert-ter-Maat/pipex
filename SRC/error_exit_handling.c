/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit_handling.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:59 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/19 10:45:45 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_double_array(char **cmd)
{
	int	index;

	index = 0;
	while (cmd[index])
	{
		free(cmd[index]);
		index++;
	}
}

void	free_before_exit(t_pipex *generate)
{	
	if (generate->cmd1)
		free_double_array(generate->cmd1);
	if (generate->cmd2)
		free_double_array(generate->cmd2);
	if (generate->split_path)
		free(generate->split_path);
	if (generate->access_path)
		free(generate->access_path);
}

void	error_exit(t_pipex *generate, const char *input)
{
	ft_printf("%s", input);
	free_before_exit(generate);
	exit(EXIT_FAILURE);
}

void	perror_exit(t_pipex *generate, const char *input)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(input);
	free_before_exit(generate);
	exit(errno);
}

void	error_access(t_pipex *generate, char *argv)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("command not found\n", STDERR_FILENO);
	free_before_exit(generate);
	exit(0);
}
