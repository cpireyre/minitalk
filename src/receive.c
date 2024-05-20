/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:54 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:31:36 by copireyr         ###   ########.fr       */
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
	g_client.pid = siginfo->si_pid;
	g_client.got = sig;
}

static unsigned char	receive_byte(void)
{
	size_t			bit_count;
	unsigned char	ret;

	bit_count = 0;
	ret = 0;
	while (bit_count < 8)
	{
		while (!g_client.got)
			usleep(1);
		if (g_client.got == SIGUSR2)
			ret |= 1 << (7 - bit_count);
		bit_count++;
		g_client.got = 0;
		kill(g_client.pid, SIGUSR1);
	}
	return (ret);
}
