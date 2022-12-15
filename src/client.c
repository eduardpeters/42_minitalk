/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epeters- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:57:41 by epeters-          #+#    #+#             */
/*   Updated: 2022/12/15 19:11:08 by epeters-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

static void	send_byte(int pid, char c)
{
	int	bits;

	bits = 8;
	while (bits-- > 0)
	{
		if (c & (1 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte(pid, str[i]);
		i++;
	}
	send_byte(pid, '\0');
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
