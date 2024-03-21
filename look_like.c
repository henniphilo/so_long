/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_like.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:46:08 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/21 10:03:37 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void show_pics(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("./looks/Wall.png")))
		perror("wall instabil\n");
	if(!(game->img.wall = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("wall is shaking");
	if(!(texture = mlx_load_png("./looks/Floor.png")))
		perror("floor is dirty");
	if(!(game->img.floor = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("floor not clean");
	if(!(texture = mlx_load_png("./looks/Exit.png")))
		perror("Exit says no");
	if(!(game->img.exit = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Exit no way");
	if(!(texture = mlx_load_png("./looks/Treasure.png")))
		perror("Collect not protact");
	if(!(game->img.treasure = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Collect not found");
	if(!(texture = mlx_load_png("./looks/Player.png")))
		perror("Player No Zero");
	if(!(game->img.player= mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Player nowhere to be found");
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
/* void	img_space(t_program *game)
{
	if(!(game->img = ft_calloc(1, sizeof(t_image))))
		perror("no space for pics");
} */
