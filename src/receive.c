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
	if (!g_state.pid)
		g_state.pid = siginfo->si_pid;
	if (siginfo->si_pid == g_state.pid)
		g_state.sig = sig;
}

void	init_signal_handler(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&(action.sa_mask));
	sigaddset(&(action.sa_mask), SIGUSR1);
	sigaddset(&(action.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}

static unsigned char	receive_byte(void)
{
	size_t		bit_count;
	unsigned char	ret;

	bit_count = 0;
	ret = 0;
	while (bit_count < 8)
	{
		while (!g_state.sig)
			usleep(1);
		if (g_state.sig == SIGUSR2)
			ret |= (1 << (7 - bit_count));
		bit_count++;
		g_state.sig = 0;
	}
	return (ret);
}
