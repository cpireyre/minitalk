/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrformat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:20:00 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/08 11:39:08 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_pointer(t_emitter *e, t_spec s, unsigned long long ptr)
{
	t_format_output	o;

	o = format_unsigned(s, ptr, "0123456789abcdef");
	o.prefix[0] = '0';
	o.prefix[1] = 'x';
	emit_int(e, &o);
}
