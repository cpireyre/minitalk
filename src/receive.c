/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:54 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/21 10:06:20 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_client	g_client;

static unsigned char	receive_byte(void);

void	*receive(void *addr, size_t size)
{
	unsigned char	*ptr;

	ft_bzero(addr, size);
	ptr = (unsigned char *) addr;
	while (size--)
		*ptr++ = receive_byte();
	return (addr);
}

void	handler(int sig, siginfo_t *siginfo, void *ctx)
{
	(void)ctx;
	if (!g_client.pid)
		g_client.pid = siginfo->si_pid;
	if (g_client.pid == siginfo->si_pid)
		g_client.signal_received = sig;
}

void	reset_client(void)
{
	g_client.pid = 0;
}

static unsigned char	receive_byte(void)
{
	size_t			bit_count;
	unsigned char	ret;

	bit_count = 0;
	ret = 0;
	while (bit_count < 8)
	{
		while (!g_client.signal_received)
			usleep(1);
		if (g_client.signal_received == SIGUSR2)
			ret |= 1 << (7 - bit_count);
		bit_count++;
		g_client.signal_received = 0;
		kill(g_client.pid, SIGUSR1);
	}
	return (ret);
}
