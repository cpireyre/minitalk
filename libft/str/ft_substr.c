/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:40:00 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:16:07 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	actual_start;
	size_t	length_substr;

	actual_start = 0;
	while (s[actual_start] && actual_start < start)
		actual_start++;
	length_substr = ft_strlen(s + actual_start);
	if (len > length_substr)
		len = length_substr;
	return (ft_strndup(s + actual_start, len));
}
