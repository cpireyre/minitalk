/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:46:36 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/09 13:32:16 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig);
static int	ft_atoi(const char *str);
static void	speak(pid_t listener, const char *str);
static void	spell(pid_t listener, char c);

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		if (BONUS)
		{
			sigemptyset(&sa.sa_mask);
			sa.sa_flags = 0;
			sa.sa_handler = &handler;
			sigaction(SIGUSR1, &sa, NULL);
		}
		server_pid = (pid_t)ft_atoi(argv[1]);
		speak(server_pid, argv[2]);
	}
	return (0);
}

static void	speak(pid_t listener, const char *str)
{
	while (*str)
	{
		spell(listener, *str);
		str++;
	}
	if (BONUS)
		spell(listener, 0);
}

static void	spell(pid_t listener, char c)
{
	int	mask;

	mask = 0;
	while (mask < 8)
	{
		if (c & (1 << mask))
			kill(listener, SIGUSR2);
		else
			kill(listener, SIGUSR1);
		mask++;
		usleep(200);
	}
}

static void	handler(int sig)
{
	(void)sig;
	write(1, "Server acknowledged the message!\n", 33);
}

static int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	sign = (*str != '-') - (*str == '-');
	str += *str == '-' || *str == '+';
	nbr = 0;
	while ('0' <= *str && *str <= '9')
		nbr = nbr * 10 + *str++ - '0';
	return (sign * nbr);
}
