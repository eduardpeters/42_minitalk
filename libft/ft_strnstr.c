/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:59:50 by epeters-          #+#    #+#             */
/*   Updated: 2021/01/22 18:52:32 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == 0)
		return ((char *)(haystack));
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while ((i + j) < len && needle[j] && haystack[i + j] == needle[j])
			{
				j++;
			}
			if (needle[j] == 0)
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
