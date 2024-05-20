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
		server = ft_atoi(argv[1]);
		msg_size = ft_strlen(argv[2]) + 1;
		send(server, &msg_size, sizeof(msg_size));
		send(server, argv[2], msg_size);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "usage: ./client server_pid message");
	}
	return (0);
}
