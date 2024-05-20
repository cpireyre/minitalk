/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strformat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:33:15 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/08 13:13:23 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format_output	strformat_bonus(t_spec s, char *str);
static void				emit_string_format(t_emitter *e, t_format_output o);

void	format_string(t_emitter *e, t_spec s, char *str)
{
	t_format_output	o;

	(void)s;
	o = strformat_bonus(s, str);
	emit_string_format(e, o);
}

static t_format_output	strformat_bonus(t_spec s, char *str)
{
	t_format_output	o;
	size_t			padding;

	ft_bzero(&o, sizeof(o));
	if (str)
		o.str = str;
	else
		o.str = "(null)";
	o.buf_len = ft_strlen(o.str);
	if (s.flags.has_precision && s.precision < o.buf_len)
		o.buf_len = s.precision;
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

static void	emit_string_format(t_emitter *e, t_format_output o)
{
	size_t	i;

	i = 0;
	while (i++ < o.left_padding)
		emit_char(e, o.pad_character);
	emit_buf(e, o.str, o.buf_len);
	i = 0;
	while (i++ < o.right_padding)
		emit_char(e, o.pad_character);
}
