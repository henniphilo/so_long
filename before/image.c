/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:59:08 by hwiemann          #+#    #+#             */
/*   Updated: 2023/09/08 16:08:00 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bpp, &img.line_size, &img.endian);
	return (img);
}

t_image ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bpp, &img.line_size, &img.endian);
	return (img);
}
/*
void	put_img(t_program *p, int height, int width)
{
	height = WINDOW_HEIGHT;
	width = WINDOW_WIDTH;

	if (p->map[height][width] == '1')
		{
			mlx_put_image_to_window(p->mlx_pointer, p->window.reference, p->image.wall,
				width * 64, height * 64);
		}
	if (p->map[height][width] == '0')
		{
			mlx_put_image_to_window(p->mlx_pointer, p->window.reference, p->image.floor,
				width * 64, height *64);
		}
	if (p->map[height][width] == 'P')
		{
			mlx_put_image_to_window(p->mlx_pointer, p->window.reference, p->image.pot,
				width * 64, height * 64);
			p->image.pot_pos_x = width;
			p->image.pot_pos_y = height;
		}
	if (p->map[height][width] == 'C')
		{
			mlx_put_image_to_window(p->mlx_pointer, p->window.reference, p->image.tea,
				width * 64, height * 64);
		}
	if (p->map[height][width] == 'E')
		{
			mlx_put_image_to_window(p->mlx_pointer, p->window.reference, p->image.cup,
				width * 64, height * 64);
		//dann game exit
		}
}
*/

