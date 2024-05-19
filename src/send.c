#include "minitalk.h"

static void	spell(pid_t listener, unsigned char byte, useconds_t delay_ms);

void	send(pid_t listener, void *addr, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) addr;
	while (size--)
		spell(listener, *ptr++, DELAY_MS);
}

static void	spell(pid_t listener, unsigned char c, useconds_t delay_ms)
{
	size_t	bit_count;
	int	signal_to_send;

	bit_count = 0;
	while (bit_count < 8)
	{
		g_state.sig = 0;
		signal_to_send = c >> (7 - bit_count) & 1;
		kill(listener, SIGUSR1 + signal_to_send);
		bit_count++;
		usleep(delay_ms);
	}
}
