/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:19:59 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/22 11:29:55 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	set_signal_handlers(t_signal_handler callback);
static void	receive_msg(size_t msg_size);

int	main(void)
{
	size_t	msg_size;
	void	*ret;

	set_signal_handlers(&handler);
	ft_printf("Server PID: %u.\n", getpid());
	while (1)
	{
		reset_client();
		ft_printf("Ready for new connection. Listening...\n");
		msg_size = 0;
		ret = receive(&msg_size, sizeof(msg_size));
		if (ret && msg_size)
			receive_msg(msg_size);
	}
	return (0);
}

static void	set_signal_handlers(t_signal_handler callback)
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
