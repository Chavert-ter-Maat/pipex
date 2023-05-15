/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:59 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/15 15:58:22 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_exit(const char *input)
{
	ft_printf("%s", input);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *input)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(input);
	exit(errno);
}

void	error_access(char *argv)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("command not found\n", STDERR_FILENO);
	exit(127);
}