/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:13:53 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/26 15:09:09 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	space_map(t_program *game, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!(line))
			perror("Error\n gnl problem");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map.map = (char **)malloc(sizeof(line) * i);
	game->map.height = i;
}

void	get_map(t_program *game, int fd)
{
	char	*line_str;
	int		i;

	i = 0;
	line_str = get_next_line(fd);
	while (line_str != NULL)
	{
		if (!(line_str))
		{
			perror("Error\nmap not readable");
			exit(1);
		}
		game->map.width = (ft_strlen(line_str) - 1);
		game->map.map[i] = ft_strdup(line_str);
		free(line_str);
		i++;
		line_str = get_next_line(fd);
	}
	if ((walls_check(game)) == 1)
	{
		perror("Error\nwalls fail");
		exit(1);
	}
}
