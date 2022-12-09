#include <signal.h>
#include <sys/types.h>
#include "../include/libft.h"

void	send_string(int	pid, char *str)
{
	int	i;
	int	bits;

	i = 0;
	while (str[i])
	{
		bits = 8;
		while (bits-- > 0)
		{
			if (str[i] & (1 << bits))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Usage: client \"PID\" \"STRING\"\n");
		return (1);
	}
	else
	{
		ft_putstr("Sending to PID: ");
		ft_putnbr(ft_atoi(argv[1]));
		ft_putstr("\nThe String: ");
		ft_putstr(argv[2]);
		ft_putchar('\n');
		send_string(ft_atoi(argv[1]), argv[2]);
	}
	return (1);
}
