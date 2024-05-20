/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:42:20 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:08:15 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_spec		spec;
	t_emitter	e;

	ft_bzero(&e, sizeof(e));
	e.fd = fd;
	while (*format)
	{
		if (*format == '%')
		{
			ft_bzero(&spec, sizeof(spec));
			spec = parse_format(++format);
			convert(&e, spec, ap);
			while (*format && !ft_strchr(CONVERSIONS, *format))
				format++;
		}
		else
		{
			emit_char(&e, *format);
		}
		if (*format)
			format++;
	}
	if (e.idx && e.written != -1)
		emit_flush(&e);
	return ((int)e.written);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (ret);
}

void	convert(t_emitter *e, t_spec s, va_list ap)
{
	if (s.conversion == UNSIGNED_CHAR)
		format_char(e, s, va_arg(ap, int));
	else if (s.conversion == STRING)
		format_string(e, s, va_arg(ap, char *));
	else if (s.conversion == POINTER)
		format_pointer(e, s, va_arg(ap, unsigned long long));
	else if (s.conversion == INTEGER)
		format_integer(e, s, va_arg(ap, int));
	else if (s.conversion == UNSIGNED_INTEGER)
		format_unsigned_integer(e, s, va_arg(ap, unsigned int));
	else if (s.conversion == LOWER_HEXADECIMAL)
		format_lower_hexadecimal(e, s, va_arg(ap, unsigned int));
	else if (s.conversion == UPPER_HEXADECIMAL)
		format_upper_hexadecimal(e, s, va_arg(ap, unsigned int));
	else if (s.conversion == PERCENT)
		format_char(e, s, '%');
}
