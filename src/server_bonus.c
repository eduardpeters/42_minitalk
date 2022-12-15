/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:33:22 by epeters-          #+#    #+#             */
/*   Updated: 2022/12/15 19:35:28 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server_bonus.h"

static void	memory_exit(void)
{
	ft_putstr("Memory allocation failed\n");
	exit(1);
}

static void	print_string(void)
{
	if (g_server_string)
	{
		ft_putstr(g_server_string);
		free(g_server_string);
		g_server_string = NULL;
	}
	return ;
}

static void	handle_incoming_char(char c, pid_t client_pid)
{
	char	str[2];
	char	*temp;

	str[0] = c;
	str[1] = '\0';
	if (c == '\0')
	{
		print_string();
		kill(client_pid, SIGUSR2);
	}
	else
	{
		if (!g_server_string)
			g_server_string = ft_strdup(str);
		else
		{
			temp = g_server_string;
			g_server_string = ft_strjoin(g_server_string, str);
			if (temp)
				free(temp);
		}
		if (!g_server_string)
			memory_exit();
	}
	return ;
}

static void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int				bits = 0;
	static unsigned char	c = 0;

	(void)(ucontext);
	if (sig == SIGUSR1)
		c |= 1;
	bits++;
	if (bits == 8)
	{
		handle_incoming_char(c, info->si_pid);
		bits = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handle_sig;
	server_pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(server_pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
