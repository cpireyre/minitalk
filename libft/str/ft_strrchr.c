/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:41:31 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/25 09:32:56 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	*ps;

	save = NULL;
	ps = (char *)s;
	while (*ps)
	{
		if (*ps == (char)c)
			save = ps;
		ps++;
	}
	if (*ps == (char)c)
		save = ps;
	return (save);
}
