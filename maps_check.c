/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/23 19:52:19 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//checken ob es erfuellbaren weg gibt

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
		printf("map.ber check done\n");
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

//	printf("fd in spac %d \n", fd);
	while((line = get_next_line(fd)) != NULL)
	{
		if(!(line))
			perror("gnl problem");
		free(line);
		i++;
	}
	game->map.map = (char**)malloc(sizeof(line) * i);
	game->map.height = i;
//	printf("map height: %d \n", game->map.height);

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
		game->map.width = (ft_strlen(line_str) - 1);
		game->map.map[i] = ft_strdup(line_str);
		free(line_str);
		i++;
	}
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
	game->count.step_count = 0;
	game->count.treasures = 0;
	game->count.player_count = 0;
	game->count.exit_count = 0;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			interpret_map(game, x, y);
			count_CPE(game, x, y);
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

void	count_CPE(t_program *game, int x, int y)
{

	if(game->map.map[y][x] == 'C')
	{
		game->count.treasures += 1;
		printf("found a treasure %d \n", game->count.treasures);
	}
	else if(game->map.map[y][x] == 'E')
	{
		game->count.exit_count += 1;
		printf("found an Exit \n");
	}
	else if(game->map.map[y][x] == 'P')
	{
		game->count.player_count += 1;
		printf("found a player \n");
	}
}

int	check_map_possible(t_program *game)
{
	if(game->count.player_count != 1)
		perror("Not enough Player \n");
	if(game->count.treasures < 1)
		perror("Nothing to win here \n");
	if(game->count.exit_count != 1)
		perror("No exit strategy \n");
	return(0);
}

int	flood_path(t_program *game, int x, int y, int *c)
{
	if(x < 0 || x >= game->map.width || y < 0 || y >= game->map.height
		|| game->map.map[y][x] == 'O' || game->map.map[y][x] == '1'
		|| game->map.map[y][x] == 'c' || game->map.map[y][x] == 'E')
	{
	 	if(game->map.map[y][x] == 'E')
	 		return (1);
		return(0);
	}

	if(game->map.map[y][x] == 'C')
	{
		(*c)--;
		game->map.map[y][x] = 'c';
	}
	else if(game->map.map[y][x] == '0')
		game->map.map[y][x] = 'O';
	flood_path(game, x, y + 1, c);
	flood_path(game, x, y - 1, c);
	flood_path(game, x + 1, y, c);
	flood_path(game, x - 1, y, c);
	return(0);
}

int		check_path(t_program *game, int x, int y, int c)
{
	printf("ausgangs y x: [%d][%d] \n", y, x);
	flood_path(game, x, y, &c);

	while(y < game->map.height)
	{
		while(x < game->map.width)
		{
			if(game->map.map[y][x] != 'c' && game->map.map[y][x] != 'P'
				&& game->map.map[y][x] != 'O' && game->map.map[y][x] != 'E'
				&& game->map.map[y][x] != '1')
				{
					printf("es hapert hier [%d][%d]", y, x);
					return(1);
				}
			else
			{
				if(game->map.map[y][x] == 'c')
					game->map.map[y][x] = 'C';
				else if(game->map.map[y][x] == 'O')
					game->map.map[y][x] = '0';
				x++;
			}
		}
		y++;
	}
	return(0);
}


