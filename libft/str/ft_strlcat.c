/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:42:53 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:42:54 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_length >= dstsize)
		return (dstsize + src_length);
	ft_strlcpy(dst + dst_length, src, dstsize - dst_length);
	return (dst_length + src_length);
}
