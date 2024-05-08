#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	handler(int sig, siginfo_t *siginfo, void *ctx)
{
	static unsigned char	byte;
	static int		count;

	(void)ctx;
	if (sig == SIGUSR2)
		byte |= 1 << count;
	count++;
	if (count == 8)
	{
		write(1, &byte, 1);
		count = 0;
		byte = 0;
	}
	usleep(100);
	//kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	pid_t			pid;
	struct sigaction	sa;

	pid = getpid();
	printf("%u\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
