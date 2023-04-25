/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:01:59 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/25 13:10:47 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(const char *input)
{
	ft_printf("%s", input);
	exit(EXIT_FAILURE);
}