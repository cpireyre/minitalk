#include "minitalk.h"

int	main(void)
{
	pid_t	server_pid;
	size_t	msg_size;
	char	*msg;
	struct sigaction	action;

	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&(action.sa_mask));
	sigaddset(&(action.sa_mask), SIGUSR1);
	sigaddset(&(action.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	server_pid = getpid();
	ft_printf("%u\n", server_pid);
	while (1)
	{
		msg_size = 0;
		receive(&msg_size, sizeof(msg_size));
		msg = malloc(msg_size);
		receive(msg, msg_size);
		write(1, msg, msg_size);
		free(msg);
	}
	return (0);
}
