/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/20 11:47:33 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/22 11:15:29 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// headers
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"

// defines
# define PIPE_WRITE_END	1
# define PIPE_READ_END	0
# define SUCCES			0
# define NOT_FOUND		0
# define FAILED			-1

// structures
typedef struct s_pipex
{
	char	**envp;
	char	*infile;
	char	*outfile;
	char	*argv2;
	char	*argv3;
	char	**cmd1;
	char	**cmd2;
	char	**split_path;
	int		pipe_fd[2];
	char	*path;
	char	*access_path;
	int		infile_fd;
	int		outfile_fd;
	pid_t	child_pid_1;
	pid_t	child_pid_2;
}	t_pipex;

// commands
void	run_command(t_pipex *generate, char *argv, char **cmd);

// input handling
void	input_handling(t_pipex *generate, int argc, char **argv, char **envp);

// error and exit handling
void	input_error(void);
void	error_exit(t_pipex *generate, const char *input);
void	perror_exit(t_pipex *generate, const char *input);
void	error_access(t_pipex *generate, char *argv);
void	free_before_exit(t_pipex *generate);

#endif