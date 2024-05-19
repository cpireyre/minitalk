#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	server;
	size_t	msg_size;

	init_signal_handler();
	if (argc == 3)
	{
		server = atoi(argv[1]);
		msg_size = strlen(argv[2]);
		send(server, &msg_size, sizeof(msg_size));
		send(server, argv[2], msg_size);
	}
	else
	{
		dprintf(STDERR_FILENO, "usage: ./client server_pid message");
	}
	return (0);
}
