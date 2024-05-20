/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:32 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:25:39 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	nop(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	pid_t	server;
	size_t	msg_size;

	signal(SIGUSR1, &nop);
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
