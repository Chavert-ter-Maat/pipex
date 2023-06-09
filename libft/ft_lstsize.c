/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 13:18:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/01 09:53:15 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Counts the number of nodes in a list.									  */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		amount;

	amount = 0;
	while (lst)
	{
		amount++;
		lst = lst->next;
	}
	return (amount);
}
