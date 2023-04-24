/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_s.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 14:30:41 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/06 14:45:54 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *string)
{
	int	index;

	index = 0;
	if (!string)
		return (-1);
	while (string[index])
	{	
		if (put_c(string[index]) == -1)
			return (-1);
		index++;
	}
	return (index);
}

int	put_s(char *string)
{
	int	index;

	index = 0;
	if (string == 0)
	{
		index = print_string("(null)");
		if (index != 6)
			return (-1);
		return (6);
	}
	while (string[index])
	{	
		if (put_c(string[index]) == -1)
			return (-1);
		index++;
	}
	return (index);
}
