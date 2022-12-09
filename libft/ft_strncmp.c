/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:07:49 by epeters-          #+#    #+#             */
/*   Updated: 2021/01/23 17:38:46 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		diff = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	if (i < n)
	{
		diff = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
		return (diff);
	}
	return (0);
}
