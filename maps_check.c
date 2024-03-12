/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 19:36:42 by hwiemann         ###   ########.fr       */
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
		mlx_image_to_window(game->mlx_pointer, game->img->wall,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map[y][x] == 'C')
	{
		mlx_image_to_window(game->mlx_pointer, game->img->treasure,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map[y][x] == 'E')
	{
		mlx_image_to_window(game->mlx_pointer, game->img->exit,(x * SSIZE), (y * SSIZE));
	}
	else
		mlx_image_to_window(game->mlx_pointer, game->img->floor,(x * SSIZE), (y * SSIZE));

}

