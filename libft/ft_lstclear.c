/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 12:11:27 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/05/01 09:55:24 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Deletes and frees the given node and every successor of that node.		  */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = head_stack;
	if (lst)
	{
		while (lst)
		{
			free(lst->next);
			lst = lst->next;
		}
	}
	free (temp);
}
