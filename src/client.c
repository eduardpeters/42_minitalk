/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:43:11 by epeters-          #+#    #+#             */
/*   Updated: 2022/12/09 11:31:33 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_bit(int pid, char c)
{
	int	bits;

	bits = 8;
	while (bits-- > 0)
	{
		if (c & (1 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

static void	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(pid, str[i]);
		i++;
	}
	send_bit(pid, '\0');
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
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
