/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:39:02 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 17:19:29 by hwiemann         ###   ########.fr       */
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
	{
		perror("invalid file extension");
		return(1);
	}
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
	//	printf("found a treasure %d \n", game->count.treasures);
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

void	check_correct_CPE(t_program *game)
{
	if((game->count.player_count != 1) || (game->count.treasures < 1) || (game->count.exit_count != 1))
		end_game(game);
	// 	perror("Not enough or too many Player \n");
	// if(game->count.treasures < 1)
	// 	perror("Nothing to win here \n");
	// if(game->count.exit_count != 1)
	// 	perror("No exit strategy \n");
}
void	print_count(t_program *game)
{
	mlx_image_to_window(game->mlx_pointer, game->img.exit, 0, 0);
//	mlx_put_string(game->mlx_pointer, "hi this is a placeholder for steps: ", 40, 40);
	mlx_put_string(game->mlx_pointer, ft_itoa(game->count.step_count) , 0, 0);
	//free itoa

	ft_printf("\rSteps: %d", game->count.step_count);
	// ft_printf("Treasures: %d \n", game->count.collects);
}
//ft_itoa(game->count.step_count)
