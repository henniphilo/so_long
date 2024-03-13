/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/13 15:31:25 by hwiemann         ###   ########.fr       */
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
	return(0);
}
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
			if(map[line - 1] != '1' || map[0][i] != '1')
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

/*char	**get_map(t_program	*game)
{
	int	fd;

	fd = open("test.ber", O_RDONLY);
	game->map = (get_next_line(fd));
} */
void	read_map(t_program *game, int x, int y)
{

	if(game->map[y][x] == '1')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.wall,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.treasure,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map[y][x] == 'E')
	{
		mlx_image_to_window(game->mlx_pointer, game->img.exit,(x * SSIZE), (y * SSIZE));
	}
	else
		mlx_image_to_window(game->mlx_pointer, game->img.floor,(x * SSIZE), (y * SSIZE));

}

