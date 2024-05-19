#include "minitalk.h"

int	main(void)
{
	pid_t	server_pid;
	size_t	msg_size;
	char	*msg;

	init_signal_handler();
	server_pid = getpid();
	printf("%u\n", server_pid);
	receive(&msg_size, sizeof(msg_size));
	msg = malloc(msg_size);
	receive(msg, msg_size);
	write(1, msg, msg_size);
	free(msg);
	return (0);
}
