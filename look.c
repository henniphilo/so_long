/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:38:37 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 19:27:52 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_space(t_program *game)
{
	if(!(game->img = ft_calloc(1, sizeof(t_image))))
		perror("no space for pics");
}

void	itsgiving_wall(t_program *game)
{
	mlx_texture_t 	*texture;

	//vor allem noch speicher allocieren?


	if(!(texture = mlx_load_png("Wall.png")))
		perror("wall is shaking");
	if(!(game->img->wall = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("wall is crumbeling");
	// if(mlx_image_to_window(game->mlx_pointer, game->img->wall, 0, 0) < 0)
	// 	perror("wall is breaking");
}

void	itsgiving_floor(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("Floor.png")))
		perror("floor is dirty");
	if(!(game->img->floor = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("floor not clean");
	// if(mlx_image_to_window(game->mlx_pointer, game->img->floor, 0, 0) < 0)
	// 	perror("floor is breaking");
}
void	itsgiving_exit(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("Exit.png")))
		perror("Exit says no");
	if(!(game->img->exit = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Exit no way");
	// if(mlx_image_to_window(game->mlx_pointer, game->img->exit, 0, 0) < 0)
	// 	perror("Exit emergency");
}
void	itsgiving_treasure(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("Treasure.png")))
		perror("Collect not protact");
	if(!(game->img->treasure = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Collect not found");
	// if(mlx_image_to_window(game->mlx_pointer, game->img->treasure, 0, 0) < 0)
	// 	perror("collect says no");
}
void	player_no_one(t_program *game)
{
	mlx_texture_t 	*texture;

	if(!(texture = mlx_load_png("Player.png")))
		perror("Player No Zero");
	if(!(game->img->player= mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("Player nowhere to be found");
	// if(mlx_image_to_window(game->mlx_pointer, game->img->player, 0, 0) < 0)
	// 	perror("player doesnt like to play");
}
