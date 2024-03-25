/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:13:53 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 12:16:18 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	space_map(t_program *game, int fd)
{
	char	*line;
	int		i = 0;

//	printf("fd in spac %d \n", fd);
	while((line = get_next_line(fd)) != NULL)
	{
		if(!(line))
			perror("gnl problem");
		free(line);
		i++;
	}
	game->map.map = (char**)malloc(sizeof(line) * i);
	game->map.height = i;
//	printf("map height: %d \n", game->map.height);

}

void	get_map(t_program *game, int fd)
{
	char	*line_str;
	int		i;

	i = 0;
	while((line_str = get_next_line(fd)) != NULL)
	{
		// if(!(line_str))
		// {
		// 		perror("map not readable") ;
		// 		exit(1);
		// }
		game->map.width = (ft_strlen(line_str) - 1);
		game->map.map[i] = ft_strdup(line_str);
		free(line_str);
		i++;
	}
	if((walls_check(game)) == 1)
	{
		perror("walls fail");
		exit(1);
	}
}
