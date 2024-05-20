/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:27:31 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 10:12:04 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"
#include "libft.h"

static char		*read_until(int fd, char *buf);
static ssize_t	extract_line(char *buf, char **line);
static char		*append(char *s1, char *s2);
char			*ft_memdel(char **ptr);

/*
 * Returns the next line from the specified file descriptor, handling
 * buffer management internally to preserve data across calls.
 */

ssize_t	ft_gnl(int fd, char **line)
{
	static char	*buf;
	char		*newline_position;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		ft_memdel(&buf);
		return (-1);
	}
	newline_position = NULL;
	if (buf)
		newline_position = ft_strchr(buf, '\n');
	if (!newline_position)
		buf = read_until(fd, buf);
	*line = NULL;
	ret = 0;
	if (buf && *buf)
		ret = extract_line(buf, line);
	if (ret == 0 || ret == -1)
		ft_memdel(&buf);
	return (ret);
}

/*
 * Reads from the file descriptor until a newline character is found
 * or EOF is reached, appending each chunk to the dynamic buffer.
 */

static char	*read_until(int fd, char *buf)
{
	char	chunk[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*newline_position;

	bytes_read = 1;
	newline_position = NULL;
	while (bytes_read > 0 && !newline_position)
	{
		bytes_read = read(fd, chunk, BUFFER_SIZE);
		chunk[bytes_read] = '\0';
		buf = append(buf, chunk);
		if (!buf)
			return (NULL);
		newline_position = ft_strchr(buf, '\n');
	}
	if (bytes_read < 0)
		ft_memdel(&buf);
	return (buf);
}

/*
 * Merges two strings, freeing the first. Ensures the dynamic buffer
 * is appropriately resized and old data discarded.
 * Because append is static and always called from read_until,
 * we know that s2 is never allocated on the heap and never null.
 */

static char	*append(char *buf, char *s2)
{
	char	*merged;
	size_t	merged_length;

	merged_length = ft_strlen(s2);
	if (buf)
		merged_length += ft_strlen(buf);
	merged = malloc(sizeof(char) * (merged_length + 1));
	if (!merged)
		return (ft_memdel(&buf));
	merged[0] = '\0';
	if (buf)
		ft_strcat(merged, buf);
	ft_strcat(merged, s2);
	free(buf);
	return (merged);
}

/*
 * Extracts one line from the buffer, adjusting the buffer to
 * remove the extracted line.
 * Manual looping here is as efficient as ft_strlen first, then
 * ft_strchr, but it makes the code simpler because it saves
 * declaring an extra pointer to do pointer arithmetic.
 * We ft_memmove remaining_length + 1 to move the \0 along.
 */

static ssize_t	extract_line(char *buf, char **line)
{
	size_t	endline_offset;
	size_t	remaining_length;

	endline_offset = 0;
	while (buf[endline_offset] && buf[endline_offset] != '\n')
		endline_offset++;
	if (buf[endline_offset] == '\n')
		endline_offset++;
	*line = ft_strndup(buf, endline_offset);
	if (!*line)
		return (-1);
	remaining_length = ft_strlen(buf) - endline_offset;
	ft_memmove(buf, buf + endline_offset, remaining_length + 1);
	return ((ssize_t)endline_offset);
}

char	*ft_memdel(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}
