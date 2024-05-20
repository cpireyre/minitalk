/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:29:56 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:47:33 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == to || len == 0)
		return (dst);
	else if (to > from && to - from < (int)len)
	{
		to += len - 1;
		from += len - 1;
		while (len--)
			*to-- = *from--;
	}
	else
		while (len--)
			*to++ = *from++;
	return (dst);
}
