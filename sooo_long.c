/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sooo_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:28:23 by hwiemann          #+#    #+#             */
/*   Updated: 2023/09/08 16:03:36 by hwiemann         ###   ########.fr       */
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

int	close_game(t_program *p)
{
	mlx_destroy_window(p->mlx_pointer, p->window.reference);
	free(p);
	exit(1);
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
	else if (key == 65307)
		close_game(p);

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
	p.image = ft_new_sprite(p.mlx_pointer, "stea-bag.xpm");
	p.img_position.x = 0;
	p.img_position.y = 0;
	mlx_put_image_to_window(p.mlx_pointer, p.window.reference, p.image.reference, p.img_position.x, p.img_position.y);
	mlx_key_hook(p.window.reference, *ft_input, &p);
	mlx_loop(p.mlx_pointer);
}
