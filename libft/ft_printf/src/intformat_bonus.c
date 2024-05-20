/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intformat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:51:05 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/08 13:13:16 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format_output	intformat_bonus(t_spec s, int n, char *base);
static void				compute_padding(t_spec s, t_format_output *o);

void	format_integer(t_emitter *e, t_spec s, int n)
{
	t_format_output	o;

	o = intformat_bonus(s, n, "0123456789");
	emit_int(e, &o);
}

/* Sign, string representation, precision, prefix, size, then padding */
/* It turns out you can't rely on bit fields casting to 0 or 1 */
/* For some reason 0 with precision 0 is a special case and doesn't print */
static t_format_output	intformat_bonus(t_spec s, int n, char *base)
{
	t_format_output	o;

	ft_bzero(&o, sizeof(o));
	if (n < 0)
		o.sign = '-';
	else if (s.flags.add_blank)
		o.sign = ' ';
	else if (s.flags.show_sign)
		o.sign = '+';
	if (!(n == 0 && s.flags.has_precision && s.precision == 0))
		o.buf_len = ft_lltoa(n, base, o.buf);
	if (s.flags.has_precision && s.precision > o.buf_len)
	{
		o.middle_padding = s.precision - o.buf_len;
		o.buf_len = s.precision;
	}
	if (o.sign)
		o.buf_len += 1;
	compute_padding(s, &o);
	return (o);
}

static void	compute_padding(t_spec s, t_format_output *o)
{
	size_t			padding;

	if (s.flags.pad_with_zeros)
		o->pad_character = '0';
	else
		o->pad_character = ' ';
	if (s.field_width > o->buf_len)
		padding = s.field_width - o->buf_len;
	else
		padding = 0;
	if (s.flags.pad_right)
		o->right_padding = padding;
	else
		o->left_padding = padding;
}
