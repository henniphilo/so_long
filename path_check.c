/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:12:52 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 17:58:19 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_path(t_program *game, int x, int y, int *c)
{
	if(x < 0 || x >= game->map.width || y < 0 || y >= game->map.height
		|| game->map.map[y][x] == 'O' || game->map.map[y][x] == '1'
		|| game->map.map[y][x] == 'c' || game->map.map[y][x] == 'E')
	{
	 	if(game->map.map[y][x] == 'E')
	 		game->exit_exists = 1;
		return ;
	}
	if(game->map.map[y][x] == '0')
		game->map.map[y][x] = 'O';
	else if(game->map.map[y][x] == 'C')
	{
		(*c)--;
		game->map.map[y][x] = 'c';
	}
	flood_path(game, x, y + 1, c);
	flood_path(game, x, y - 1, c);
	flood_path(game, x + 1, y, c);
	flood_path(game, x - 1, y, c);
}

int		check_path(t_program *game, int x, int y, int c)
{
	flood_path(game, x, y, &c);
	if (game->exit_exists != 1)
		return(1);
	y = 0;
	while(y < game->map.height)
	{
		x = 0;
		while(x < game->map.width)
		{
			if(game->map.map[y][x] != 'c' && game->map.map[y][x] != 'P' && game->map.map[y][x] != 'O'
				&& game->map.map[y][x] != '0' && game->map.map[y][x] != 'E'
				&& game->map.map[y][x] != '1')
							return(1);
			else
			{
				if(game->map.map[y][x] == 'c')
					game->map.map[y][x] = 'C';
				else if(game->map.map[y][x] == 'O')
					game->map.map[y][x] = '0';
				x++;
			}
		}
		y++;
	}
	return(0);
}
