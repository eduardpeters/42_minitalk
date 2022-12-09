/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:05 by epeters-          #+#    #+#             */
/*   Updated: 2021/01/26 16:39:23 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstptr;
	t_list	*lstnext;

	if (lst && *lst && del)
	{
		lstptr = *lst;
		while (lstptr)
		{
			lstnext = lstptr->next;
			ft_lstdelone(lstptr, del);
			lstptr = lstnext;
		}
		*lst = NULL;
	}
}
