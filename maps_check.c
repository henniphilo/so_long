/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 22:01:06 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	check_map_ber(char *file)
{
	int	i;

	i = 0;
	while(file[i] != '\0')
		i++;
	i--;
	if(file[i] != 'r' || file[i - 1] != 'e' || file[i - 2] != 'b'
		|| file[i - 3] != '.')
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

void	count_CPE(t_program *game, int x, int y)
{
	if(game->map.map[y][x] == 'C')
	{
		game->count.treasures += 1;
	}
	if(game->map.map[y][x] == 'E')
		game->count.exit_count += 1;
	if(game->map.map[y][x] == 'P')
		game->count.player_count += 1;
}

void	check_correct_CPE(t_program *game)
{
	if((game->count.player_count != 1) || (game->count.treasures < 1)
		|| (game->count.exit_count != 1))
	{
		perror("Error \n C/P/E in map not correct\n");
		end_game(game);
		exit(0);
	}
	ft_printf("Treasures to collect: %d \n", game->count.treasures);
}
void	print_count(t_program *game)
{
	char	*str;

	str = ft_itoa(game->count.step_count);
	mlx_image_to_window(game->mlx_pointer, game->img.bg, 0, 0);
	mlx_put_string(game->mlx_pointer, str , 0, 0);
	free(str);
	ft_printf("\rSteps: %d", game->count.step_count);
}
