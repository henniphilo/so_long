/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:34:36 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/26 11:35:46 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
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

char	*gnl_strchr(const char *s, int c)
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
