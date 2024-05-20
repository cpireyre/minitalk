/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:35:21 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/06 13:49:41 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_BONUS_H
# define FORMAT_BONUS_H

typedef struct s_format_output
{
	char	buf[32];
	size_t	left_padding;
	size_t	middle_padding;
	size_t	right_padding;
	size_t	buf_len;
	size_t	total_len;
	char	*str;
	char	prefix[2];
	char	pad_character;
	char	sign;
}	t_format_output;

#endif
