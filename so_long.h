/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:29:27 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/13 15:30:46 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//#include <mlx.h>
#include "MLX42/MLX42.h"
#include "./libft/libft.h"
#include <stddef.h>
#include <stdio.h>


# define	WIN_HEIGHT	600
# define	WIN_WIDTH	900
# define	SSIZE		16

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*treasure;
	mlx_image_t	*exit;
}	t_image;

typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
	char	**map;
	t_image	img;
	t_image	*old_img;
	mlx_image_t	*wall2;
}	t_program;

char	**get_map(t_program *game);
int		check_map_ber(char *file);
void	read_map(t_program *game, int x, int y);
//void	img_space(t_program *game);
void	clean_pics(t_program *game);
int		walls_check(char **map);
void	show_pics(t_program *game);








#endif
