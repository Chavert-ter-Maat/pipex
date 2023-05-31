/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit_handling.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:59 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/31 10:33:16 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_error(void)
{
	ft_putstr_fd("wrong input: infile cmd1 cmd2 outfile\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	error_exit(char *input)
{
	ft_putstr_fd(input, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *input)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(input);
	exit(errno);
}

void	error_no_command(char *argv)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("command not found\n", STDERR_FILENO);
	exit(127);
}
