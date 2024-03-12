/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:38:37 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 15:52:44 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*itsgiving_wall()
{
	mlx_texture_t 	*texture;
	mlx_image_t		*image;
	t_program		*game;

	if(!(texture = mlx_load_png("Wall.png")))
		perror("wall is shaking");
	if(!(image = mlx_texture_to_image(game->mlx_pointer, texture)))
		perror("wall is crumbeling");
	if(mlx_image_to_window(game->mlx_pointer, image, 0, 0) < 0)
		perror("wall is breaking");
	return(image);
}

