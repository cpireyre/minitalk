/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:54 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:27:56 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	got;
static volatile sig_atomic_t	pid;

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
	pid = siginfo->si_pid;
	got = sig;
}

static unsigned char	receive_byte(void)
{
	size_t			bit_count;
	unsigned char	ret;

	bit_count = 0;
	ret = 0;
	while (bit_count < 8)
	{
		while (!got)
			usleep(1);
		if (got == SIGUSR2)
			ret |= 1 << (7 - bit_count);
		bit_count++;
		got = 0;
		kill(pid, SIGUSR1);
	}
	return (ret);
}
