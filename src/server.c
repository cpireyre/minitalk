/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:46:35 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/09 13:14:28 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putnbr(unsigned int n);
static void	ft_putstr(const char *str);
static void	handler(int sig, siginfo_t *siginfo, void *ctx);

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	if (BONUS)
		ft_putstr("This server will talk back.\n");
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep(1);
	}
	return (0);
}

static void	handler(int sig, siginfo_t *siginfo, void *ctx)
{
	static unsigned char	byte;
	static int				count;

	(void)ctx;
	if (sig == SIGUSR2)
		byte |= 1 << count;
	count++;
	if (count == 8)
	{
		write(1, &byte, 1);
		if (BONUS && byte == '\0')
			kill(siginfo->si_pid, SIGUSR1);
		count = 0;
		byte = 0;
	}
}

static void	ft_putnbr(unsigned int n)
{
	unsigned int	nbr;
	char			c;

	nbr = (unsigned int)(n * (n > 0) - n * (n < 0));
	if (nbr >= 10)
		ft_putnbr((int)(nbr / 10));
	c = (int)(nbr % 10 + '0');
	write(1, &c, 1);
}

static void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}
