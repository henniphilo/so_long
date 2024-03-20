/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:29:27 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/20 13:44:33 by hwiemann         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

typedef struct s_program
{
	mlx_t	*mlx_pointer;
	void	*window;
	t_map	map;
	t_image	img;
	t_image	*old_img;
	mlx_image_t	*wall2;
}	t_program;

void	get_map(t_program *game, int fd);
void	interpret_map(t_program *game, int x, int y);
void	clean_pics(t_program *game);
void	show_pics(t_program *game);
void	map_init(t_program *game);
void	open_map(t_program *game);
void	game_on(t_program *game);
void	space_map(t_program *game, int fd);
char	*get_next_line(int fd);



int		map_empty(char **map);
int		check_map_ber(char *file);
int		walls_check(char **map);



#endif
