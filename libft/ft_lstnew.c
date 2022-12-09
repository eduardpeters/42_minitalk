/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:20:47 by epeters-          #+#    #+#             */
/*   Updated: 2021/01/26 17:55:20 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlst;

	newlst = (t_list *)(malloc(sizeof(*newlst)));
	if (!newlst)
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}
