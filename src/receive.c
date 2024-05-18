#include "minitalk.h"

static unsigned char	receive_byte(void);

void	*receive(void *addr, size_t size)
{
	unsigned char	*ptr;

	bzero(addr, size);
	ptr = (unsigned char *) addr;
	while (size--)
		*ptr++ = receive_byte();
	return (addr);
}

void	handler(int sig, siginfo_t *siginfo, void *ctx)
{
	(void)ctx;
	g_state.sig = sig;
	g_state.pid = siginfo->si_pid;
}

static unsigned char	receive_byte(void)
{
	size_t		bit_count;
	unsigned char	ret;

	bit_count = 0;
	ret = 0;
	while (bit_count < 8)
	{
		pause();
		if (g_state.sig == SIGUSR2)
			ret |= (1 << (7 - bit_count));
		bit_count++;
		g_state.sig = 0;
	}
	return (ret);
}
