/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_like_to_move_it.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:13:26 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/26 12:47:42 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_y(mlx_key_data_t key)
{
	if (key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
		return (-1);
	else if (key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
		return (1);
	else
		return (0);
}

static int	get_x(mlx_key_data_t key)
{
	if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
		return (-1);
	else if (key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
		return (1);
	else
		return (0);
}

static void	player_no_one(t_program *game, int y, int x)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->map.player.pos_x;
	pos_y = game->map.player.pos_y;
	if (game->map.map[pos_y + y][pos_x + x] != '1')
	{
		pos_y += y;
		pos_x += x;
		game->count.step_count += 1;
	}
	if (game->map.map[pos_y][pos_x] == 'C')
	{
		game->count.collects += 1;
		ft_printf("\nTreasures collected: %d \n", game->count.collects);
		game->map.map[pos_y][pos_x] = '0';
	}
	if (game->map.map[game->map.player.pos_y][game->map.player.pos_x] != 'E')
		mlx_image_to_window(game->mlx_pointer, game->img.floor,
			(game->map.player.pos_x * SSIZE), (game->map.player.pos_y * SSIZE));
	if (game->map.map[pos_y][pos_x] == 'E')
		end_game(game);
	mlx_image_to_window(game->mlx_pointer, game->img.player, (pos_x * SSIZE),
		(pos_y * SSIZE));
	game->map.player.pos_x = pos_x;
	game->map.player.pos_y = pos_y;
}

void	check_end(t_program *game)
{
	if (game->count.treasures != 0
		&& game->count.collects == game->count.treasures)
		ft_printf("\nCongrats!\n");
	else if (game->count.collects < game->count.treasures)
		ft_printf("\nGame over. Not enough Treasures collected \n");
	else
		ft_printf("\nGame Over \n");
}

void	key_hook(mlx_key_data_t key, void *ptr)
{
	t_program	*game;
	int			x;
	int			y;

	x = 0;
	y = 0;
	game = ptr;
	if (key.action == MLX_RELEASE)
	{
		if (key.key == MLX_KEY_ESCAPE)
			end_game(game);
		else
		{
			y = get_y(key);
			x = get_x(key);
		}
		player_no_one(game, y, x);
		print_count(game);
	}
}
