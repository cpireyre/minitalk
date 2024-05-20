/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:19 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/06 14:12:28 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMIT_H
# define EMIT_H

# include <sys/types.h>
# include <unistd.h>

# define EMITTER_BUFFER_SIZE 256

/* If you define and enforce a hard cap you get snprintf almost for free */

typedef struct s_emitter
{
	char	buf[EMITTER_BUFFER_SIZE];
	size_t	idx;
	ssize_t	written;
	int		fd;
}				t_emitter;

void	emit_char(t_emitter *e, char c);
void	emit_string(t_emitter *e, char *s);
void	emit_buf(t_emitter *e, char *buf, size_t len);
void	emit_int(t_emitter *e, t_format_output *o);
void	emit_flush(t_emitter *e);

#endif
