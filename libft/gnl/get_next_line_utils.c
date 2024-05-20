/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:53:52 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:13:10 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dst, const char *src);
char	*ft_strndup(const char *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			i;

	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == to || len == 0)
		return (dst);
	else if (to > from && to - from < (int)len)
	{
		i = len;
		while (--i >= 0)
			to[i] = from[i];
	}
	else
	{
		i = -1;
		while (++i < len)
			to[i] = from[i];
	}
	return (dst);
}
