/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:11:51 by epeters-          #+#    #+#             */
/*   Updated: 2021/01/26 15:52:15 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*end;

	if (alst)
	{
		if (*alst)
		{
			end = ft_lstlast(*alst);
			end->next = new;
		}
		else
			*alst = new;
	}
}
