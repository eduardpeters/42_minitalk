/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:00:11 by epeters-          #+#    #+#             */
/*   Updated: 2022/06/19 17:46:36 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_n_size(int n)
{
	size_t			size;
	unsigned int	u_nbr;

	size = 2;
	if (n < 0)
	{
		size += 1;
		u_nbr = (unsigned int)(n * -1);
	}
	else
		u_nbr = (unsigned int)(n);
	while (u_nbr > 9)
	{
		u_nbr = u_nbr / 10;
		size += 1;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t			size;
	unsigned int	u_nbr;
	char			*str;

	size = ft_get_n_size(n);
	str = (char *)(malloc(sizeof(*str) * size));
	if (!str)
		return (NULL);
	if (n < 0)
		u_nbr = (unsigned int)(n * -1);
	else
		u_nbr = (unsigned int)(n);
	str[size - 1] = '\0';
	size -= 2;
	while (size > 0)
	{
		str[size] = '0' + (u_nbr % 10);
		u_nbr = u_nbr / 10;
		size--;
	}
	if (n < 0)
		str[size] = '-';
	else
		str[size] = '0' + (u_nbr % 10);
	return (str);
}
