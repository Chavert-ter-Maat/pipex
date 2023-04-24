/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_u.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 15:44:10 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/06 14:43:54 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa(unsigned int number)
{
	unsigned int	string_lenght;
	char			*string;

	string_lenght = get_lenght(number);
	string = malloc((string_lenght + 1) * sizeof(char));
	if (!string)
		return (0);
	if (number == 0)
		string[0] = '0';
	string[string_lenght] = '\0';
	if (number < 0)
	{
		string[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		string[string_lenght - 1] = (number % 10) + '0';
		number /= 10;
		string_lenght--;
	}
	return (string);
}

int	put_u(unsigned int u)
{
	char	*string;

	string = ft_itoa(u);
	if (!string)
		return (-1);
	if (print_string(string) == -1)
		return (free(string), -1);
	free (string);
	return (get_lenght(u));
}
