/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:13:34 by epeters-          #+#    #+#             */
/*   Updated: 2022/07/15 17:15:39 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	u_nbr;

	if (n < 0)
	{
		ft_putchar('-');
		u_nbr = (unsigned int)(n * -1);
	}
	else
		u_nbr = (unsigned int)(n);
	if (u_nbr > 9)
	{
		ft_putnbr(u_nbr / 10);
		ft_putnbr(u_nbr % 10);
	}
	else
		ft_putchar('0' + u_nbr);
}
