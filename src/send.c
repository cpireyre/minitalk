/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:19:05 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/21 10:08:14 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	spell(pid_t listener, unsigned char byte, useconds_t delay_ms);

int	send(pid_t listener, void *addr, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) addr;
	while (size--)
		if (spell(listener, *ptr++, DELAY_MS))
			return (1);
	return (0);
}

static int	spell(pid_t listener, unsigned char c, useconds_t delay_ms)
{
	size_t	bit_count;
	int		signal_to_send;

	bit_count = 0;
	while (bit_count < 8)
	{
		signal_to_send = c >> (7 - bit_count) & 1;
		if (kill(listener, SIGUSR1 + signal_to_send))
			return (1);
		bit_count++;
		(void)delay_ms;
		usleep(delay_ms * 100);
	}
	return (0);
}
