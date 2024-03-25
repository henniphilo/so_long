/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_like.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:46:08 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 17:47:30 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void show_pics(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("./looks/Wall.png")))
		perror("Error \n wall instabil\n");
	if(!(game->img.wall = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n wall is shaking");
	if(!(texture = mlx_load_png("./looks/Floor.png")))
		perror("Error \n floor is dirty");
	if(!(game->img.floor = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n floor not clean");
	if(!(texture = mlx_load_png("./looks/Exit.png")))
		perror("Error \nExit says no");
	if(!(game->img.exit = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \nExit no way");
	if(!(texture = mlx_load_png("./looks/Treasure.png")))
		perror("Error \n Collect not protact");
	if(!(game->img.treasure = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n Collect not found");
	if(!(texture = mlx_load_png("./looks/Player.png")))
		perror("Error \n Player No Zero");
	if(!(game->img.player= mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Error \n Player nowhere to be found");
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
