/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:42:06 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:45:28 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*res;

	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	len = 0;
	while (s[len])
	{
		res[len] = f(len, s[len]);
		len++;
	}
	res[len] = '\0';
	return (res);
}
