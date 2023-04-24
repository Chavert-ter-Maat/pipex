/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 11:47:33 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/24 16:35:08 by cter-maa      ########   odam.nl         */
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
}	t_pipex;

// SRC
void	initialize(t_pipex *generate, int argc, char **argv, char **envp);
// void	run_command(char **argv, char **envp);

#endif