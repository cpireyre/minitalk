/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:17 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/21 10:46:29 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"

# ifndef DELAY_MS
#  define DELAY_MS	500
# endif

typedef struct s_client
{
	volatile sig_atomic_t	signal_received;
	volatile sig_atomic_t	pid;
}	t_client;

int		send(pid_t listener, void *addr, size_t size);
void	*receive(void *addr, size_t size);
void	handler(int sig, siginfo_t *siginfo, void *ctx);
void	reset_client(void);

typedef void	(*t_signal_handler)(int, struct __siginfo *, void *);

# define ERROR_LOST_SERVER		"ERROR: Lost server during transmission.\n"
# define ERROR_USAGE			"usage: ./client server_pid message\n"
# define ERROR_CLIENT_TIMED_OUT	"ERROR: Client timed out.\n"

/* Ten seconds */
# define TIMEOUT_DELAY_MICROSECONDS 10000000

#endif
