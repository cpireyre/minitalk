#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	server;
	size_t	msg_size;
	struct sigaction	action;

	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&(action.sa_mask));
	sigaddset(&(action.sa_mask), SIGUSR1);
	sigaddset(&(action.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	printf("Client pid %d\n", getpid());
	if (argc == 3)
	{
		msg_size = strlen(argv[2]);
		printf("%s: %zu\n", argv[2], msg_size);
		server = atoi(argv[1]);
		send(server, &msg_size, sizeof(msg_size));
		printf("Sent msg size %zu", msg_size);
		send(server, argv[2], msg_size);
	}
	else
	{
		dprintf(STDERR_FILENO, "usage: ./client server_pid message");
	}
}
