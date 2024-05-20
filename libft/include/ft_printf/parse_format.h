/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:51:12 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/02 14:52:29 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FORMAT_H
# define PARSE_FORMAT_H

/* We (only) have to support cspdiuxX% */
# define CONVERSIONS	"cspdiuxX%"

typedef enum e_conversion
{
	UNSIGNED_CHAR,
	STRING,
	POINTER,
	INTEGER,
	UNSIGNED_INTEGER,
	LOWER_HEXADECIMAL,
	UPPER_HEXADECIMAL,
	PERCENT,
	IDENTITY
}		t_conversion;

/* 
 * printf flags:
 * Alternate form: #
 * 0 padding: 0
 * Right padding: -
 * Show blank: [space]
 * Show sign: +
 */

typedef struct s_flags
{
	unsigned char	alternate_form	: 1;
	unsigned char	pad_with_zeros	: 1;
	unsigned char	pad_right	: 1;
	unsigned char	add_blank	: 1;
	unsigned char	show_sign	: 1;
	unsigned char	has_precision	: 1;
}				t_flags;

typedef struct s_spec
{
	t_flags			flags;
	unsigned int	field_width;
	unsigned int	precision;
	t_conversion	conversion;
}		t_spec;

t_spec	parse_format(const char *format);

#endif
