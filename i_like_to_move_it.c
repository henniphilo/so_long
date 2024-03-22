/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_like_to_move_it.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:13:26 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/22 16:32:37 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_y(mlx_key_data_t key)
{
	if(key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
		return(-1);
	else if(key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
		return(1);
	else
		return (0);
}

static	int	get_x(mlx_key_data_t key)
{
 	if(key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
		return(-1);
	else if(key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
		return(1);
	else
		return(0);
}

static void	player_no_one(t_program *game, int y, int x)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->map.player.pos_x;
	pos_y = game->map.player.pos_y;
	if(game->map.map[pos_y + y][pos_x + x] != '1')
	{
		pos_y += y;
		pos_x += x;
	}
	if(game->map.map[pos_y + y][pos_x + x] == 'C')
		game->count.collects += 1;
	mlx_image_to_window(game->mlx_pointer, game->img.player,(pos_x * SSIZE), (pos_y * SSIZE));
	if(game->map.map[pos_y - y][pos_x - x] != 'E')
		mlx_image_to_window(game->mlx_pointer, game->img.floor,((pos_x - (x))* SSIZE), ((pos_y - (y)) * SSIZE));
	else if (game->map.map[pos_y][pos_x] == 'E')
		end_game(game);
	game->map.player.pos_x = pos_x;
	game->map.player.pos_y = pos_y;
}

void	check_end(t_program *game)
{
	if(game->count.collects == game->count.treasures)
		ft_printf("Congrats!\n");
	else
		ft_printf("Game Over \n");
}

void	end_game(t_program *game)
{
	check_end(game);
	mlx_close_window(game->mlx_pointer);
}

void	key_hook(mlx_key_data_t key, void *ptr)
{
	t_program	*game;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game = ptr;
	if(key.action == MLX_RELEASE)
	{
		game->count.step_count += 1;
		if(key.key == MLX_KEY_ESCAPE)
			end_game(game);
		else
		{
			y =	get_y(key);
			x = get_x(key);
		}
	}
	player_no_one(game, y, x);
	print_count(game);
}
//macht alles immer doppelt
// und wenn umgeben von wallls removed walls

void	print_count(t_program *game)
{
	ft_printf("Steps: %d \n", game->count.step_count);
	ft_printf("Treasures: %d \n", game->count.collects);
}
