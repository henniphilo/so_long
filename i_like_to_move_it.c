/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_like_to_move_it.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:13:26 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/22 10:59:21 by hwiemann         ###   ########.fr       */
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
	if(key.action == MLX_PRESS)
	{
		if(key.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx_pointer);
		//while(game->mlx_pointer)

		else if(key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
			y = 1;
		else if(key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
			y = -1;
		else if(key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
			x = -1;
		else if(key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
			x = 1;
		
	}
	printf(" P : [%d] [%d] \n",game->map.player.pos_y, game->map.player.pos_x);
	if(game->map.map[game->map.player.pos_y][game->map.player.pos_x] != '1')
	{
		game->map.player.pos_y += y;
		game->map.player.pos_x += x;
	}
}


//wie verankern? woher kommt key?
