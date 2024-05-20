/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charformat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:01:06 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/08 13:13:10 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format_output	charformat_bonus(t_spec s, int c);
static void				emit_char_with_format(t_emitter *e, t_format_output o);

void	format_char(t_emitter *e, t_spec s, int c)
{
	t_format_output	o;

	o = charformat_bonus(s, c);
	emit_char_with_format(e, o);
}

static t_format_output	charformat_bonus(t_spec s, int c)
{
	t_format_output	o;
	size_t			padding;

	ft_bzero(&o, sizeof(o));
	o.buf[0] = c;
	o.buf_len = 1;
	if (s.flags.pad_with_zeros)
		o.pad_character = '0';
	else
		o.pad_character = ' ';
	if (s.field_width > o.buf_len)
		padding = s.field_width - o.buf_len;
	else
		padding = 0;
	if (s.flags.pad_right)
		o.right_padding = padding;
	else
		o.left_padding = padding;
	return (o);
}

static void	emit_char_with_format(t_emitter *e, t_format_output o)
{
	size_t	i;

	i = 0;
	while (i++ < o.left_padding)
		emit_char(e, o.pad_character);
	emit_char(e, o.buf[0]);
	i = 0;
	while (i++ < o.right_padding)
		emit_char(e, o.pad_character);
}
