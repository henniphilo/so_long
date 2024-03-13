/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:46:08 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/13 15:18:50 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void new_start(t_program *game)
{
	mlx_texture_t 	*texture;
	//mlx_image_t		*image;


	ft_printf("GAME: %p\n", game);

	if(!(texture = mlx_load_png("Wall.png")))
		exit(1);

	ft_printf("TEXTURE: %p\n", texture);

	//if(!(game->wall2 = mlx_texture_to_image(game->mlx_pointer, texture)))
	if(!(game->img.wall = mlx_texture_to_image(game->mlx_pointer, texture)))
		exit(1);

	//ft_printf("image: %p\n", game->wall2);
	ft_printf("image: %p\n", game->img.wall);


//	if(mlx_image_to_window(game->mlx_pointer, game->wall2, 0, 0) < 0)
	// if(mlx_image_to_window(game->mlx_pointer, game->img.wall, 0, 0) < 0)
	// 	exit(1);

	//ft_printf("image: %p\n", image);
}
