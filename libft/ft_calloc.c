/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <epeters-@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:32:14 by epeters-          #+#    #+#             */
/*   Updated: 2022/06/24 16:08:10 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	mem_size;

	mem_size = count * size;
	if (count != 0 && (mem_size / count != size))
		return (NULL);
	mem = malloc(mem_size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (mem_size));
	return (mem);
}
