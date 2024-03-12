/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:26:46 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 16:55:25 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_buffers(char **buffer, char *next_line, int free_result)
{
	free(*buffer);
	*buffer = NULL;
	if (free_result)
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
	while ((!ft_strchr(*buffer, '\n') && **buffer != *"") || **buffer == '\0')
	{
		next_line = gnl_strjoin(next_line, *buffer, ft_strlen(*buffer) + 1);
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
	if (ft_strchr(*buffer, '\n'))
	{
		next_line = gnl_strjoin(next_line, *buffer, ft_strchr(*buffer, '\n')
				- *buffer + 2);
		ft_strlcpy(*buffer, ft_strchr(*buffer, '\n') + 1,
			ft_strlen(ft_strchr(*buffer, '\n')));
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
