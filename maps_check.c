/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/21 11:42:16 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//noch checken ob alle anwesend sind 1 e p 0 c
//checken ob es erfuellbaren weg gibt
//moves zaehlen

void	open_map(t_program *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		perror("fd open error");
	check_map_ber(file);
	space_map(game, fd); //map.map gemalloct und height initialisiert
	close(fd);
	fd = open(file, O_RDONLY);
	get_map(game, fd); //width initialisiert und in map.map kopiert damm walls check
	close(fd);
}

int	check_map_ber(char *file)
{
	int	i;

	i = 0;
	while(file[i] != '\0')
		i++;
	i -= 1;
	if(file[i] != 'r' || file[i - 1] != 'e' || file[i - 2] != 'b'
		|| file[i - 3] != '.')
		perror("invalid file extension");
	else
		printf("map check done\n");
	return(0);
}


int	map_empty(char **map)
{
	if(map[0])
		return(1);
	return(0);
}

int	walls_check(t_program *game)
{
	char	**map = game->map.map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < game->map.width)
	{
		if(map[(game->map.height) - 1][0] != '1' || map[0][i] != '1'
			|| map[game->map.height - 1][i] != '1')
				return (1);
		i++;
	}
	while(j < game->map.height)
	{
		if(map[j][0] != '1' || map[0][(game->map.width) - 1] != '1'
			|| map[j][game->map.width - 1] != '1')
				return (1);
		j++;
	}
	return (0);
}


void	space_map(t_program *game, int fd)
{
	char	*line;
	int		i = 0;

	printf("fd in spac %d \n", fd);
	while((line = get_next_line(fd)) != NULL)
	{
		if(!(line))
			perror("gnl problem");
		free(line);
		i++;
	}
	game->map.map = (char**)malloc(sizeof(line) * i);
	game->map.height = i;
	printf("map height: %d \n", game->map.height);

}

void	get_map(t_program *game, int fd)
{
	char	*line_str;
	int		i;

	i = 0;
	while((line_str = get_next_line(fd)) != NULL)
	{
		// if(!(line_str))
		// {
		// 		perror("map not readable") ;
		// 		exit(1);
		// }
		printf("in get map line %s . \n", line_str);
		game->map.width = (ft_strlen(line_str) - 1);
		game->map.map[i] = ft_strdup(line_str);
		free(line_str);
		i++;
	}
	printf(" width : %d \n", game->map.width);
	if((walls_check(game)) == 1)
	{
		perror("walls fail");
		exit(1);
	}
}

void	map_init(t_program *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			interpret_map(game, x, y);
			x++;
		}
		y++;
	}
}


void	interpret_map(t_program *game, int x, int y)
{
	if(game->map.map[y][x] == '1')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.wall,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map.map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.treasure,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map.map[y][x] == 'E')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.exit,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map.map[y][x] == 'P')
	{
		game->map.player.pos_y = y;
		game->map.player.pos_x = x;
		mlx_image_to_window(game->mlx_pointer, game->img.player,(x * SSIZE), (y * SSIZE));
	}
	else
		mlx_image_to_window(game->mlx_pointer, game->img.floor,(x * SSIZE), (y * SSIZE));

}

