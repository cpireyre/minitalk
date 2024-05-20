/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:55:30 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/06 15:10:33 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags		read_flags(const char *format);
static unsigned int	read_field_width(const char *format);
static unsigned int	read_precision(const char *format);
static t_conversion	read_conversion(const char *format);

/* Takes format string and returns struct for the current
 * conversion.
 * After we read the data from the format string, we need
 * to check two little bits of logic:
 *	1) if a precision is given with a numeric conversion,
 * 	the 0 flag is ignored,
 *	2) - overrides 0 if both are given.
 */

t_spec	parse_format(const char *format)
{
	t_spec	spec;
	t_flags	flags;
	int		conversion_is_numeric;

	ft_bzero(&spec, sizeof(spec));
	flags = read_flags(format);
	spec.field_width = read_field_width(format);
	spec.precision = read_precision(format);
	spec.conversion = read_conversion(format);
	conversion_is_numeric = spec.conversion == INTEGER
		| spec.conversion == UNSIGNED_INTEGER
		| spec.conversion == LOWER_HEXADECIMAL
		| spec.conversion == UPPER_HEXADECIMAL;
	flags.pad_with_zeros &= ~(conversion_is_numeric & flags.has_precision);
	flags.pad_with_zeros &= ~flags.pad_right;
	flags.add_blank &= ~flags.show_sign;
	spec.flags = flags;
	return (spec);
}

/* Takes format string and returns an unsigned char
 * with all the right bits flipped.
 * Note the call to bzero, flipping bits in an uninitialised
 * integer doesn't trigger compile warnings apparently.
 */

static t_flags	read_flags(const char *format)
{
	t_flags	flags;
	char	ignore_zero;

	ignore_zero = 0;
	ft_bzero(&flags, sizeof(t_flags));
	while (*format && !ft_strchr(CONVERSIONS, *format))
	{
		if ('1' <= *format && *format <= '9')
			ignore_zero = 1;
		flags.alternate_form |= *format == '#';
		flags.pad_with_zeros |= *format == '0' && !ignore_zero;
		flags.pad_right |= *format == '-';
		flags.add_blank |= *format == ' ';
		flags.show_sign |= *format == '+';
		flags.has_precision |= *format == '.';
		format++;
	}
	return (flags);
}

static unsigned int	read_field_width(const char *format)
{
	while ((*format
			&& !ft_strchr(CONVERSIONS, *format)
			&& *format != '.'
			&& !ft_isdigit(*format))
		|| *format == '0')
		format++;
	if (ft_isdigit(*format))
		return ((unsigned int)ft_atoi(format));
	return (0);
}

static unsigned int	read_precision(const char *format)
{
	while (*format && *format != '.' && !ft_strchr(CONVERSIONS, *format))
		format++;
	if (*format == '.')
		return ((unsigned int)ft_atoi(++format));
	return (0);
}

static t_conversion	read_conversion(const char *format)
{
	t_conversion	conversion_mappings[127];

	conversion_mappings['c'] = UNSIGNED_CHAR;
	conversion_mappings['s'] = STRING;
	conversion_mappings['p'] = POINTER;
	conversion_mappings['d'] = INTEGER;
	conversion_mappings['i'] = INTEGER;
	conversion_mappings['u'] = UNSIGNED_INTEGER;
	conversion_mappings['x'] = LOWER_HEXADECIMAL;
	conversion_mappings['X'] = UPPER_HEXADECIMAL;
	conversion_mappings['%'] = PERCENT;
	while (*format && !ft_strchr(CONVERSIONS, *format))
		format++;
	if (*format)
		return (conversion_mappings[(int)*format]);
	return (IDENTITY);
}
