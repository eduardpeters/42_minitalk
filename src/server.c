#include <signal.h>
#include <sys/types.h>
#include "../include/libft.h"

void	handle_sig(int	sig)
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
	c <<= 1;
}

int	main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(server_pid);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, handle_sig);
		signal(SIGUSR2, handle_sig);
		pause();
	}
	return (1);
}
