#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void	spell(pid_t listener, char c);

void	speak(pid_t listener, const char *str)
{
	while (*str)
	{
		spell(listener, *str);
		str++;
	}
}

void	spell(pid_t listener, char c)
{
	int	mask;

	mask = 0;
	while (mask < 8)
	{
		if (c & (1 << mask))
			kill(listener, SIGUSR2);
		else
			kill(listener, SIGUSR1);
		mask++;
		usleep(500);
	}
}

void	handler(int sig)
{
}

int	main(int argc, char **argv)
{
	pid_t			server_pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		server_pid = (pid_t)atoi(argv[1]);
		speak(server_pid, argv[2]);
	}
	return (0);
}
