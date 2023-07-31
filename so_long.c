/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:32:51 by hwiemann          #+#    #+#             */
/*   Updated: 2023/07/31 16:17:23 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include <stdlib.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

typedef struct	s_data {
	void	*
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
/*
 typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode, t_vars *vars) //need to use keycode esc
{
	mlx_destroy_window(data->mlx, vars->win);
	return (0);
}


// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
//	t_vars	vars;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Sooooo Long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00a4ffa4);
	my_mlx_pixel_put(&img, 5, 9, 0x00a4ffa4);
	my_mlx_pixel_put(&img, 5, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 13, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 15, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 20, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 25, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_hook(vars.win, 2, 1L<<0, close, &vars.win);
	mlx_loop(mlx);
}
/*
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}*/

