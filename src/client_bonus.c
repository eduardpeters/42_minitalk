/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:58:08 by epeters-          #+#    #+#             */
/*   Updated: 2022/12/15 19:17:34 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client_bonus.h"

static void	send_bit(pid_t pid, char c)
{
	static int	bits = 8;

	if (bits-- > 0)
	{
		if (c & (1 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
	}
	if (bits == 0)
		bits = 8;
}

static void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 0;
	static int	sig_sent = 1;
	static int	sig_confirmed = 0;

	(void)(ucontext);
	if (sig == SIGUSR2)
	{
		ft_putstr("Signals acknowledged: ");
		ft_putnbr(++sig_confirmed);
		ft_putstr(" / ");
		ft_putnbr(sig_sent);
		ft_putchar('\n');
		exit(0);
	}
	sig_confirmed++;
	if (g_client_string[i])
	{
		send_bit(info->si_pid, g_client_string[i]);
		if (sig_confirmed > 7 && sig_confirmed % 8 == 0)
			i++;
	}
	else
		send_bit(info->si_pid, '\0');
	sig_sent++;
}

static int	check_pid(char *str)
{
	if (!str)
		return (0);
	while (ft_isdigit(*str))
			str++;
	if (*str)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3)
	{
		ft_putstr("Usage: client \"PID\" \"STRING\"\n");
		return (1);
	}
	if (!check_pid(argv[1]))
	{
		ft_putstr("PID must be a number\n");
		return (1);
	}
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handle_sig;
	g_client_string = argv[2];
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	send_bit(ft_atoi(argv[1]), g_client_string[0]);
	while (1)
		pause();
	return (0);
}
