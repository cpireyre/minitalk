/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:19:59 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/21 10:05:35 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_signal_handlers(t_signal_handler callback);

int	main(void)
{
	size_t				msg_size;
	char				*msg;

	ft_dprintf(STDERR_FILENO, "Initialising server...\n");
	set_signal_handlers(&handler);
	ft_printf("Server PID: %u.\n", getpid());
	while (1)
	{
		ft_dprintf(STDERR_FILENO, "Listening...");
		msg_size = 0;
		receive(&msg_size, sizeof(msg_size));
		msg = malloc(msg_size);
		receive(msg, msg_size);
		ft_printf(" message received!\n-> ");
		write(1, msg, msg_size);
		ft_printf("\n");
		free(msg);
		reset_client();
	}
	return (0);
}

void	set_signal_handlers(t_signal_handler callback)
{
	struct sigaction	action;

	action.sa_sigaction = callback;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&(action.sa_mask));
	sigaddset(&(action.sa_mask), SIGUSR1);
	sigaddset(&(action.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
}
