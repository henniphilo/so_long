/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:32:51 by hwiemann          #+#    #+#             */
/*   Updated: 2023/08/21 19:07:25 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "so_long.h"

typedef struct s_img {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}				t_data;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(img, j++, i, color);
		}
		++i;
	}
}

int	esc_keypress(int keysym, t_data *data)
{
	if(keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	t_img	img;

	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, 0xFFFFFF);
		my_mlx_pixel_put(&img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0xFF0000);
	return (0);
}


int	main(void)
{
	t_data	data;
	t_img	img;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Sooooo Long");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len,
								&data.img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00a4ffa4);
	my_mlx_pixel_put(&img, 5, 9, 0x00a4ffa4);
	my_mlx_pixel_put(&img, 5, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 13, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 15, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 20, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 25, 0x00FF0000);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &esc_keypress, &data);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_hook(vars.win, 2, 1L<<0, close, &vars.win);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

*/
