/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:43:23 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:46:09 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_words(const char *s, char c);
static char		*ft_strcdup(const char *src, char c);
static char		**free_split(char **split, size_t last);

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**split;
	size_t	i;

	words = count_words(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			split[i] = ft_strcdup(s, c);
			if (!split[i])
				return (free_split(split, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	split[i] = NULL;
	return (split);
}

static size_t	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static char	*ft_strcdup(const char *src, char c)
{
	size_t	i;
	size_t	j;
	char	*dup;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = src[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}

static char	**free_split(char **split, size_t last)
{
	size_t	i;

	i = 0;
	while (i < last)
		free(split[i++]);
	free(split);
	return (NULL);
}
