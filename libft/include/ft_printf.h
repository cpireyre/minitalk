/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:50:58 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:08:03 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "libft.h"
# include "./ft_printf/parse_format.h"
# include "./ft_printf/format_bonus.h"
# include "./ft_printf/emit.h"
# include "./ft_printf/ft_ulltoa.h"

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
t_format_output	format_unsigned(t_spec s, unsigned long n, char *base);
int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_printf(const char *format, ...);
void			convert(t_emitter *e, t_spec s, va_list ap);
void			format_integer(t_emitter *e, t_spec s, int n);
void			format_unsigned_integer(t_emitter *e, t_spec s, unsigned int n);
void			format_lower_hexadecimal(t_emitter *e, t_spec s,
					unsigned int n);
void			format_upper_hexadecimal(t_emitter *e, t_spec s,
					unsigned int n);
void			format_pointer(t_emitter *e, t_spec s, unsigned long long ptr);
void			format_string(t_emitter *e, t_spec s, char *str);
void			format_char(t_emitter *e, t_spec s, int c);

#endif
