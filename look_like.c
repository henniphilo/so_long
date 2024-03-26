/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_like.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:46:08 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/26 11:32:59 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_program *game)
{
	game->texture.wall = mlx_load_png("./looks/Wall.png");
	game->texture.floor = mlx_load_png("./looks/Floor.png");
	game->texture.exit = mlx_load_png("./looks/Exit.png");
	game->texture.player = mlx_load_png("./looks/Player.png");
	game->texture.treasure = mlx_load_png("./looks/Treasure.png");
	game->texture.bg = mlx_load_png("./looks/bg.png");
	if (!(game->texture.wall) || !(game->texture.bg) || !(game->texture.exit)
		|| !(game->texture.wall) || !(game->texture.floor))
	{
		perror("Error\n texture load\n");
		exit(1);
	}
}

void	show_pics(t_program *game)
{
	get_textures(game);
	game->img.wall = mlx_texture_to_image(game->mlx_pointer,
			game->texture.wall);
	game->img.floor = mlx_texture_to_image(game->mlx_pointer,
			game->texture.floor);
	game->img.exit = mlx_texture_to_image(game->mlx_pointer,
			game->texture.exit);
	game->img.treasure = mlx_texture_to_image(game->mlx_pointer,
			game->texture.treasure);
	game->img.player = mlx_texture_to_image(game->mlx_pointer,
			game->texture.player);
	game->img.bg = mlx_texture_to_image(game->mlx_pointer, game->texture.bg);
	clean_texture(game);
}

void	clean_pics(t_program *game)
{
	mlx_delete_image(game->mlx_pointer, game->img.exit);
	mlx_delete_image(game->mlx_pointer, game->img.wall);
	mlx_delete_image(game->mlx_pointer, game->img.treasure);
	mlx_delete_image(game->mlx_pointer, game->img.player);
	mlx_delete_image(game->mlx_pointer, game->img.floor);
}

void	clean_texture(t_program *game)
{
	mlx_delete_texture(game->texture.bg);
	mlx_delete_texture(game->texture.exit);
	mlx_delete_texture(game->texture.floor);
	mlx_delete_texture(game->texture.player);
	mlx_delete_texture(game->texture.treasure);
	mlx_delete_texture(game->texture.wall);
}
