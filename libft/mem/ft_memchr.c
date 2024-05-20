/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:29:00 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:47:13 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		if (ps[i] == (unsigned char)c)
			return (ps + i);
		i++;
	}
	return (NULL);
}
