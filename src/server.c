/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:44:36 by epeters-          #+#    #+#             */
/*   Updated: 2022/12/09 11:14:26 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_sig(int sig)
{
	static int				bits;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c |= 1;
	bits++;
	if (bits == 8)
	{
		ft_putchar(c);
		bits = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(server_pid);
	ft_putchar('\n');
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
		pause();
	return (1);
}
