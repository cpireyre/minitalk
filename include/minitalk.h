/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:18:17 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:18:28 by copireyr         ###   ########.fr       */
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

void	send(pid_t listener, void *addr, size_t size);
void	*receive(void *addr, size_t size);
void	handler(int sig, siginfo_t *siginfo, void *ctx);

#endif
