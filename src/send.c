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
    kill(listener, SIGUSR1 + ((c >> 7) & 1));
    usleep(delay_ms);
    kill(listener, SIGUSR1 + ((c >> 6) & 1));
    usleep(delay_ms);
    kill(listener, SIGUSR1 + ((c >> 5) & 1));
    usleep(delay_ms);
    kill(listener, SIGUSR1 + ((c >> 4) & 1));
    usleep(delay_ms);
    kill(listener, SIGUSR1 + ((c >> 3) & 1));
    usleep(delay_ms);
    kill(listener, SIGUSR1 + ((c >> 2) & 1));
    usleep(delay_ms);
    kill(listener, SIGUSR1 + ((c >> 1) & 1));
    usleep(delay_ms);
    kill(listener, SIGUSR1 + ((c >> 0) & 1));
    usleep(delay_ms);
}
