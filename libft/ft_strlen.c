/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 13:25:48 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/25 15:37:31 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ft_strlen() function computes the length of the string s.				  */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	lenght;
	// char	*string;

	lenght = 0;
	// string = (char *)s;
	// if (s == NULL)
	// 	return (0);
	while (s[lenght])
		lenght++;
	return (lenght);
}
