/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sooo_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:28:23 by hwiemann          #+#    #+#             */
/*   Updated: 2023/09/06 11:42:21 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, width, height, name);
	window.size.x = width;
	window.size.y = height;

	mlx_hook(window.reference, 17, 0, ft_close, 0); //17 to close window
	return(window);
}

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

int	ft_input(int key, void *param)
{
	t_program	*p = (t_program *)param;

	mlx_clear_window(p->mlx_pointer, p->window.reference);

	if (key == 65363)
		p->img_position.x += p->image.size.x;
	else if (key == 65361)
		p->img_position.x -= p->image.size.x;
	else if (key == 65364)
		p->img_position.y += p->image.size.y;
	else if (key == 65362)
		p->img_position.y -= p->image.size.y;
	/*else if (key == 15)
		turn_img_to_color(&p->image, new_color(255,0,0,0));
	else if (key == 5)
		turn_img_to_color(&p->image, new_color(0,255,0,0));
	else if (key == 11)
		turn_img_to_color(&p->image, new_color(0,0,255,0));*/
	mlx_put_image_to_window(p->mlx_pointer, p->window.reference, p->image.reference, p->img_position.x, p->img_position.y);
	printf("key pressed: %d\n", key);
	return (0);
}

int main(void)
{
	t_program	p;

	p.mlx_pointer = mlx_init();
	if (!p.mlx_pointer)
		return (MLX_ERROR);
	p.window = ft_new_window(p.mlx_pointer, WINDOW_WIDTH, WINDOW_HEIGHT, "HI HENNI");
	p.image = ft_new_sprite(p.mlx_pointer, "teapot.xpm");
	p.img_position.x = 0;
	p.img_position.y = 0;
	mlx_put_image_to_window(p.mlx_pointer, p.window.reference, p.image.reference, p.img_position.x, p.img_position.y);
	mlx_key_hook(p.window.reference, *ft_input, &p);
	mlx_loop(p.mlx_pointer);
}
