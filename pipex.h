/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 11:47:33 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/01 14:43:05 by cter-maa      ########   odam.nl         */
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
# define PIPE_WRITE_END	1
# define PIPE_READ_END	0
# define FAILED		-1



// structures
typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	int		argc;
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	int		pipe_fd[2];
	char	*path;
}	t_pipex;

// commands
void	run_command(t_pipex *generate);

// initialize
void	initialize(t_pipex *generate, int argc, char **argv, char **envp);

// utils
void	error(const char *input);

#endif