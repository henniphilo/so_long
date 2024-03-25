/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:33:45 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 20:00:21 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(t_program *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		perror("Error \n fd open error");
	if(check_map_ber(file) == 1)
	{
		perror("Error \n no .ber file");
		exit(0) ;
	}
	space_map(game, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	get_map(game, fd);
	close(fd);
}

void	map_init(t_program *game)
{
	int	x;
	int	y;
	game->count.step_count = 0;
	game->count.treasures = 0;
	game->count.player_count = 0;
	game->count.exit_count = 0;
	game->count.collects = 0;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			interpret_map(game, x, y);
			count_CPE(game, x, y);
			x++;
		}
		y++;
	}
}

void	interpret_map(t_program *game, int x, int y)
{
	if(game->map.map[y][x] == '1')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.wall,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map.map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.treasure,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map.map[y][x] == 'E')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.exit,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map.map[y][x] == 'P')
	{
		game->map.player.pos_y = y;
		game->map.player.pos_x = x;
		mlx_image_to_window(game->mlx_pointer, game->img.player,(x * SSIZE), (y * SSIZE));
	}
	else
		mlx_image_to_window(game->mlx_pointer, game->img.floor,(x * SSIZE), (y * SSIZE));
}

