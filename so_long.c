/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 14:08:11 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close()
{
	exit(0);
}


t_program	window()
{
	t_program		ptr;
	mlx_texture_t 	*texture;
	mlx_image_t		*image;

	if(!(ptr.mlx_pointer = mlx_init(WIN_WIDTH, WIN_HEIGHT, "hello again", true)))
		exit(1);

	if(!(texture = mlx_load_png("Fulgens.png")))
		exit(1);

	if(!(image = mlx_texture_to_image(ptr.mlx_pointer, texture)))
		exit(1);

	if(mlx_image_to_window(ptr.mlx_pointer, image, 0, 0) < 0)
		exit(1);

	mlx_loop(ptr.mlx_pointer);

	return(ptr);
}

int	main()
{
	window();
	return(0);
}
