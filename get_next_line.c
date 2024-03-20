/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:46 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/20 11:05:16 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
static char	*free_buffers(char **buffer, char *next_line, int free_result)
{
	free(*buffer);
	*buffer = NULL;
	if (free_result && next_line)
		free(next_line);
	return (NULL);
}

static char	*gnl_strjoin(char *s1, const char *s2, size_t size)
{
	char	*result;

	result = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, size);
	free(s1);
	return (result);
}

static char	*read_line(int fd, char **buffer, char *next_line, int *chars_read)
{
	while (((!ft_strchr(*buffer, '\n')) && **buffer != '\0') || **buffer == '\0')
	{
		next_line = gnl_strjoin(next_line, *buffer, ft_strlen(*buffer) + 1);
		*chars_read = read(fd, *buffer, BUFFER_SIZE);
		if (*chars_read < 0)
			return (free_buffers(buffer, next_line, 1));
		if (*chars_read == 0)
		{
			if (*next_line == '\0')
				return (free_buffers(buffer, next_line, 1));
			return (next_line);
		}
		(*buffer)[*chars_read] = '\0';
	}
	if (ft_strchr(*buffer, '\n'))
	{
		next_line = gnl_strjoin(next_line, *buffer, ft_strchr(*buffer, '\n')
				- *buffer + 1);
		ft_strlcpy(*buffer, ft_strchr(*buffer, '\n') + 1, *chars_read);
	}
	if (next_line == NULL)
		return (free_buffers(buffer, next_line, 1));
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*next_line;
	int			chars_read;

	next_line = NULL;
	chars_read = 0;
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (free_buffers(&buffer, next_line, 0));
		buffer[chars_read] = '\0';
	}
	return (read_line(fd, &buffer, next_line, &chars_read));
}
*/


static size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src)
	{
		if (size == 0)
			return (gnl_strlen(src));
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (gnl_strlen(src));
}

static char	*gnl_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((unsigned char)*s == (unsigned char) c)
	{
		return ((char *) s);
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, const char *s2, size_t size)
{
	char	*result;

	result = malloc((gnl_strlen(s1) + gnl_strlen(s2)) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	gnl_strlcpy(result, s1, gnl_strlen(s1) + 1);
	gnl_strlcpy(result + gnl_strlen(s1), s2, size);
	free(s1);
	return (result);
}
static char	*free_buffers(char **buffer, char *next_line, int free_result)
{
	free(*buffer);
	*buffer = NULL;
	if (free_result)
		free(next_line);
	return (NULL);
}

static char	*read_line(int fd, char **buffer, char *next_line, int *chars_read)
{
	while ((!gnl_strchr(*buffer, '\n') && **buffer != *"") || **buffer == '\0')
	{
		next_line = gnl_strjoin(next_line, *buffer, gnl_strlen(*buffer) + 1);
		*chars_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[*chars_read] = 0;
		if (*chars_read < 0)
			return (free_buffers(buffer, next_line, 1));
		if (*chars_read == 0)
		{
			if (*next_line == *"")
				return (free_buffers(buffer, next_line, 1));
			return (next_line);
		}
	}
	if (gnl_strchr(*buffer, '\n'))
	{
		next_line = gnl_strjoin(next_line, *buffer, gnl_strchr(*buffer, '\n')
				- *buffer + 2);
		gnl_strlcpy(*buffer, gnl_strchr(*buffer, '\n') + 1,
			gnl_strlen(gnl_strchr(*buffer, '\n')));
	}
	if (next_line == 0)
		return (free_buffers(buffer, next_line, 1));
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;
	int			chars_read;

	next_line = 0;
	chars_read = 0;
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (free_buffers(&buffer, next_line, 0));
		buffer[chars_read] = 0;
	}
	return (read_line(fd, &buffer, next_line, &chars_read));
}

