/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:44:36 by epeters-          #+#    #+#             */
/*   Updated: 2022/12/09 13:37:19 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
/*
static void	print_bits(unsigned char c)
{
	int	bits;

	bits = 8;
	while (bits-- > 0)
	{
		if (c & (1 << bits))
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
}
*/

static void	handle_sig_int(int sig)
{
	if (sig == SIGINT)
		ft_putstr("SIGINT received, exiting program\n");
	else
		ft_putstr("Unable to allocate memory, exiting program\n");
	exit(1);
}

static void	handle_incoming_char(char c)
{
	char	str[2];
	char	*temp;

	str[0] = c;
	str[1] = '\0';
	if (c == '\0')
	{
		ft_putstr(g_server_string);
		free(g_server_string);
		g_server_string = NULL;
	}
	else if (!g_server_string)
		g_server_string = ft_strdup(str);
	else
	{
		temp = g_server_string;
		g_server_string = ft_strjoin(g_server_string, str);
		if (temp)
			free(temp);
		if (!g_server_string)
			handle_sig_int(0);
	}
}

static void	handle_sig(int sig)
{
	static int				bits = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c |= 1;
	bits++;
	if (bits == 8)
	{
		handle_incoming_char(c);
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
	signal(SIGINT, handle_sig_int);
	while (1)
		pause();
	return (0);
}
