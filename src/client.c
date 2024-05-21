/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:32 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/21 10:16:18 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	nop(int sig);
static int	wrap_send_error(pid_t server, void *addr, size_t size);

int	main(int argc, char **argv)
{
	pid_t	server;
	size_t	msg_size;

	signal(SIGUSR1, &nop);
	if (argc == 3)
	{
		server = ft_atoi(argv[1]);
		ft_printf("Sending message...\n");
		msg_size = ft_strlen(argv[2]) + 1;
		if (wrap_send_error(server, &msg_size, sizeof(msg_size)))
			return (1);
		if (wrap_send_error(server, argv[2], msg_size))
			return (1);
		ft_printf("Done.\n");
	}
	else
	{
		ft_dprintf(STDERR_FILENO, ERROR_USAGE);
		return (1);
	}
	return (0);
}

static void	nop(int sig)
{
	(void)sig;
}

static int	wrap_send_error(pid_t server, void *addr, size_t size)
{
	int	err;

	err = send(server, addr, size);
	if (err)
	{
		ft_dprintf(STDERR_FILENO, ERROR_LOST_SERVER);
		return (1);
	}
	return (0);
}
