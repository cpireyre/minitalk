/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:41:41 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:41:42 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_length;
	size_t	needle_length;

	if (!*needle)
		return ((char *)haystack);
	haystack_length = ft_strlen(haystack);
	needle_length = ft_strlen(needle);
	while (len >= needle_length && haystack_length >= needle_length)
	{
		if (ft_strncmp(haystack, needle, needle_length) == 0)
			return ((char *)haystack);
		haystack++;
		haystack_length--;
		len--;
	}
	return (NULL);
}
