/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 11:47:33 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/25 16:26:19 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// headers
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"

// defines

// structures
typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	int		argc;
	char	*path;
}	t_pipex;

// commands
void	run_command(t_pipex *generate);

// initialize
void	initialize(t_pipex *generate, int argc, char **argv, char **envp);
void	print_envp(t_pipex *generate);

// utils
void	error(const char *input);


#endif