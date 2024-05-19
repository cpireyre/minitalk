#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h> // remove this
# include <string.h> // remove this
# include <signal.h>
# include <stdlib.h>

# ifndef DELAY_MS
#   define DELAY_MS	300
# endif

typedef struct
{
	int	sig;
	int	pid;
}	t_signal_state;

static volatile t_signal_state g_state;

void	send(pid_t listener, void *addr, size_t size);
void	*receive(void *addr, size_t size);
void	handler(int sig, siginfo_t *siginfo, void *ctx);
void	init_signal_handler(void);

#endif
