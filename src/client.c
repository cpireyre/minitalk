#include "minitalk.h"

void	noop(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	pid_t	server;
	size_t	msg_size;

	signal(SIGUSR1, &noop);
	if (argc == 3)
	{
		server = atoi(argv[1]);
		msg_size = strlen(argv[2]) + 1;
		puts("Sending size");
		send(server, &msg_size, sizeof(msg_size));
		puts("Sending message");
		send(server, argv[2], msg_size);
	}
	else
	{
		dprintf(STDERR_FILENO, "usage: ./client server_pid message");
	}
}
