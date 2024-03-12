/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 15:53:15 by hwiemann         ###   ########.fr       */
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
char	**get_map(char *map)
{


}
void	read_map(t_program *game, int x, int y)
{
	mlx_image_t	*wall = itsgiving_wall();

	if(game->map[y][x] == '1')
	{
		mlx_image_to_window(game->mlx_pointer, wall,(x * SSIZE), (y * SSIZE));
	}
	else if(game->map[y][x] == 'C')
	{
		//collactable
	}
	else if(game->map[y][x] == 'E')
	{
		//enemy pic
	}
	else
		//floor

}

