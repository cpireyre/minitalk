/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:32 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/23 09:08:30 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	nop(int sig);
static int	send(pid_t listener, void *addr, size_t size);
static int	send_byte(pid_t listener, unsigned char c, useconds_t delay_ms);
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

static int	send(pid_t listener, void *addr, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) addr;
	while (size--)
		if (send_byte(listener, *ptr++, DELAY_MS))
			return (1);
	return (0);
}

static int	send_byte(pid_t listener, unsigned char c, useconds_t delay_ms)
{
	size_t	bit_count;
	int		signal_to_send;

	bit_count = 0;
	while (bit_count < 8)
	{
		if (c >> (7 - bit_count) & 1)
			signal_to_send = SIGUSR2;
		else
			signal_to_send = SIGUSR1;
		if (kill(listener, signal_to_send))
			return (1);
		usleep(delay_ms * 100);
		bit_count++;
	}
	return (0);
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
