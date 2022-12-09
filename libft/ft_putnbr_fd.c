/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:13:45 by epeters-          #+#    #+#             */
/*   Updated: 2022/06/19 18:45:18 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u_nbr = (unsigned int)(n * -1);
	}
	else
		u_nbr = (unsigned int)(n);
	if (u_nbr > 9)
	{
		ft_putnbr_fd(u_nbr / 10, fd);
		ft_putnbr_fd(u_nbr % 10, fd);
	}
	else
		ft_putchar_fd('0' + u_nbr, fd);
}
