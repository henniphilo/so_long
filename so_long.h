/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:11:34 by hwiemann          #+#    #+#             */
/*   Updated: 2023/09/06 11:49:35 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define MLX_ERROR 1
#define RED_PIXEL 0xFF0000

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

//a pointer to the window and its size
typedef struct s_window
{
	void	*reference;
	t_position	size;
}	t_window;

typedef struct s_image
{
	void	*reference;
	t_position	size;
	char	*pixels;
	int		bpp;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_program
{
	void	*mlx_pointer;
	t_window	window;
	t_image		image;
	t_position	img_position;
}	t_program;

int	ft_close();
int	ft_input(int key, void *param);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);

t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image	ft_new_image(void *mlx, int width, int height);
t_image ft_new_sprite(void *mlx, char *path);

#endif
