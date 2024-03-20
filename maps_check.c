/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/20 13:53:08 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

//map lesen und **maps mallocen , dafuer braucht es zeilen zaehlen



int	map_empty(char **map)
{
	if(map[0])
		return(1);
	return(0);
}

int	walls_check(char **map)
{
	int	line;
	int	i;
	int	j;

	i = 0;
	j = 0;
	line = 0;
	while(map[line])
		line++;
	while(i < ft_strlen(map[0]))
		{
			if(map[line - 1][0] != '1' || map[0][i] != '1')
				return (1);
			i++;
		}
	while(j < (line - 1))
	{
		if(map[j][0] != '1' || map[ft_strlen(map[0])][0] != '1')
				return (1);
			j++;
	}
	return (0);
}
void	open_map(t_program *game)
{
	int	fd;

	fd = open("test.ber", O_RDONLY);
	if(fd < 0)
		perror("fd open error");
	printf("fd nach open %d \n", fd);
	check_map_ber("test.ber");
	space_map(game, fd);
	close(fd);
	fd = open("test.ber", O_RDONLY);
	get_map(game, fd);
	// if(walls_check(game->map.map) == 1)
	// 	perror("walls fail");
	close(fd);
}
void	space_map(t_program *game, int fd)
{
	char	*line;
	int		i = 0;

	printf("fd in spac %d \n", fd);
	while((line = get_next_line(fd)) != NULL)
	{
		printf("while space line: %s \n", line);
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
	printf("get map fd %d\n", fd);

	while((line_str = get_next_line(fd)) != NULL)
	{
		printf("in get map loop \n");
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
	printf("map width : %d \n", game->map.width);
	//game->map.height = i;
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
	printf(" interpret map y : %d \n", y);
	printf(" interpret map x : %d \n", x);

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
	else
		mlx_image_to_window(game->mlx_pointer, game->img.floor,(x * SSIZE), (y * SSIZE));

}

