/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:53:16 by epeters-          #+#    #+#             */
/*   Updated: 2022/06/17 18:12:51 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_s;
	int		i;

	c = (char)(c);
	i = ft_strlen(s);
	ptr_s = (char *)(s);
	while (i >= 0)
	{
		if (*(ptr_s + i) == c)
			return (ptr_s + i);
		i--;
	}
	return (NULL);
}
