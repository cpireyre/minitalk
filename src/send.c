/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:19:05 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:27:37 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	spell(pid_t listener, unsigned char byte, useconds_t delay_ms);

void	send(pid_t listener, void *addr, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) addr;
	while (size--)
		spell(listener, *ptr++, DELAY_MS);
}

static void	spell(pid_t listener, unsigned char c, useconds_t delay_ms)
{
	size_t	bit_count;
	int		signal_to_send;

	bit_count = 0;
	while (bit_count < 8)
	{
		signal_to_send = c >> (7 - bit_count) & 1;
		kill(listener, SIGUSR1 + signal_to_send);
		bit_count++;
		usleep(delay_ms);
	}
}
