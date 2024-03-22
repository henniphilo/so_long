/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_like_to_move_it.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:13:26 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/22 13:20:45 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t key, void *ptr)
{
	t_program	*game;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game = ptr;
//	ft_printf("steps count: %d \n", game->count);
	if(key.action == MLX_PRESS)
	{
		game->count += 1;
		if(key.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx_pointer);
			//end_game function to clean up properly
		//while(game->mlx_pointer)
		else if(key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
			y = -1;
		else if(key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
			y = 1;
		else if(key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
			x = -1;
		else if(key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
			x = 1;

	}
//	printf(" P : [%d] [%d] \n",game->map.player.pos_y, game->map.player.pos_x);
	if(game->map.map[game->map.player.pos_y + y][game->map.player.pos_x + x] != '1')
	{
		game->map.player.pos_y += y;
		game->map.player.pos_x += x;
	}
	mlx_image_to_window(game->mlx_pointer, game->img.player,(game->map.player.pos_x * SSIZE), (game->map.player.pos_y * SSIZE));
	if(game->map.map[game->map.player.pos_y - y][game->map.player.pos_x - x] != 'E')
		mlx_image_to_window(game->mlx_pointer, game->img.floor,((game->map.player.pos_x - (x))* SSIZE), ((game->map.player.pos_y - (y)) * SSIZE));
	print_count(game);
	//macht alles immer doppelt
}

void	print_count(t_program *game)
{
	ft_printf("Steps: %d \n", game->count);
	ft_printf("Treasures: %d \n", game->collects);
}
