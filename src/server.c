/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:19:59 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/23 08:50:14 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_client	g_client;
static void	handler(int sig, siginfo_t *siginfo, void *ctx);
static void	receive_msg(size_t msg_size);
static void	*receive(void *addr, size_t size);
static int	receive_byte(unsigned char *byte);

int	main(void)
{
	size_t				msg_size;
	void				*ret;
	struct sigaction	action;

	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&(action.sa_mask));
	sigaddset(&(action.sa_mask), SIGUSR1);
	sigaddset(&(action.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("Server PID: %u.\n", getpid());
	while (1)
	{
		g_client.pid = 0;
		ft_printf("Ready for new connection. Listening...\n");
		msg_size = 0;
		ret = receive(&msg_size, sizeof(msg_size));
		if (ret && msg_size)
			receive_msg(msg_size);
	}
	return (0);
}

static void	handler(int sig, siginfo_t *siginfo, void *ctx)
{
	(void)ctx;
	if (!g_client.pid)
		g_client.pid = siginfo->si_pid;
	if (g_client.pid == siginfo->si_pid)
		g_client.signal_received = sig;
}

static void	receive_msg(size_t msg_size)
{
	char	*msg;

	msg = malloc(msg_size + 1);
	if (msg)
	{
		msg[msg_size] = '\0';
		if (receive(msg, msg_size))
			ft_printf("「 %s 」\n", msg);
		else
			ft_dprintf(STDERR_FILENO, ERROR_CLIENT_TIMED_OUT);
		free(msg);
	}
	else
		ft_dprintf(STDERR_FILENO, "ERROR: malloc fail\n");
}

static void	*receive(void *addr, size_t size)
{
	unsigned char	*ptr;
	int				err;

	ft_bzero(addr, size);
	ptr = (unsigned char *) addr;
	while (size--)
	{
		err = receive_byte(ptr++);
		if (err)
			return (NULL);
	}
	return (addr);
}

static int	receive_byte(unsigned char *byte)
{
	size_t	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		while (!g_client.signal_received)
		{
			usleep(TIMEOUT_DELAY_MICROSECONDS);
			if (!g_client.signal_received)
				return (1);
		}
		if (g_client.signal_received == SIGUSR2)
			*byte |= 1 << (7 - bit_count);
		bit_count++;
		g_client.signal_received = 0;
		kill(g_client.pid, SIGUSR1);
	}
	return (0);
}
