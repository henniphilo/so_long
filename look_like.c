/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_like.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:46:08 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 22:09:38 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void show_pics(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("./looks/Wall.png")))
		exit(1);
	if(!(game->img.wall = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n wall is shaking");
	mlx_delete_texture(texture);
	if(!(texture = mlx_load_png("./looks/Floor.png")))
		exit(1);
	if(!(game->img.floor = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n floor not clean");
	mlx_delete_texture(texture);
	if(!(texture = mlx_load_png("./looks/Exit.png")))
		exit(1);
	if(!(game->img.exit = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \nExit no way");
	mlx_delete_texture(texture);
}

void show_pic2(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("./looks/Treasure.png")))
		exit(1);
	if(!(game->img.treasure = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n Collect not found");
	mlx_delete_texture(texture);
	if(!(texture = mlx_load_png("./looks/Player.png")))
		exit(1);
	if(!(game->img.player= mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n Player nowhere to be found");
	mlx_delete_texture(texture);
	if(!(texture = mlx_load_png("./looks/bg.png")))
		exit(1);
	if(!(game->img.bg = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n wall is shaking");
	mlx_delete_texture(texture);
}

void	clean_pics(t_program *game)
{
	mlx_delete_image(game->mlx_pointer, game->img.exit);
	mlx_delete_image(game->mlx_pointer, game->img.wall);
	mlx_delete_image(game->mlx_pointer, game->img.treasure);
	mlx_delete_image(game->mlx_pointer, game->img.player);
	mlx_delete_image(game->mlx_pointer, game->img.floor);
}
