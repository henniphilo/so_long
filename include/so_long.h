/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:29:27 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/26 14:23:06 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <stddef.h>
# include <stdio.h>
# include <string.h>

# define SSIZE	31

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*treasure;
	mlx_image_t	*exit;
	mlx_image_t	*bg;
}	t_image;

typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*treasure;
	mlx_texture_t	*exit;
	mlx_texture_t	*bg;
}	t_texture;

typedef struct s_sprite
{
	t_image		look;
	int			pos_x;
	int			pos_y;
}	t_sprite;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	int			moves;
	t_sprite	player;
}	t_map;

typedef struct s_count
{
	int			step_count;
	int			collects;
	int			treasures;
	int			player_count;
	int			exit_count;
}	t_count;

typedef struct s_program
{
	mlx_t		*mlx_pointer;
	t_map		map;
	t_image		img;
	t_texture	texture;
	t_sprite	sprite;
	t_count		count;
	bool		exit_exists;
}	t_program;

void	get_map(t_program *game, int fd);
void	interpret_map(t_program *game, int x, int y);
void	clean_pics(t_program *game);
void	show_pics(t_program *game);
void	map_init(t_program *game);
void	open_map(t_program *game, char *file);
void	game_on(t_program *game);
void	space_map(t_program *game, int fd);
void	key_hook(mlx_key_data_t key, void *ptr);
void	print_count(t_program *game);
void	check_end(t_program *game);
void	end_game(t_program *game);
void	count_cpe(t_program *game, int x, int y);
void	free_map(t_program *game);
void	flood_path(t_program *game, int x, int y, int *c);
void	check_correct_cpe(t_program *game);
void	get_textures(t_program *game);
void	clean_texture(t_program *game);

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, const char *s2, size_t size);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
size_t	gnl_strlen(const char *s);

int		check_path(t_program *game, int x, int y, int c);
int		check_map_ber(char *file);
int		walls_check(t_program *game);

#endif
