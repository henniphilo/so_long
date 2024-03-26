/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/26 12:47:47 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	hook(void *ptr)
{
	t_program	*game;

	game = ptr;
}

void	game_on(t_program *game)
{
	ft_printf("Game On\n Collect all blue tiles \n");
	game->mlx_pointer = mlx_init((SSIZE * game->map.width),
			(SSIZE * game->map.height), "hello again", false);
	if (!(game->mlx_pointer))
		perror("Error \n init error");
}

void	end_game(t_program *game)
{
	check_end(game);
	mlx_close_window(game->mlx_pointer);
}

void	free_map(t_program *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

int	main(int argc, char **argv)
{
	t_program	game;
	char		*file;

	if (argc == 2)
	{
		file = argv[1];
		open_map(&game, file);
		game_on(&game);
		show_pics(&game);
		map_init(&game);
		check_correct_cpe(&game);
		if (check_path(&game, game.map.player.pos_x,
				game.map.player.pos_y, game.count.treasures) == 1)
		{
			perror("Error \n fd path not valid \n");
			end_game(&game);
		}
		mlx_loop_hook(game.mlx_pointer, &hook, &game);
		mlx_key_hook(game.mlx_pointer, &key_hook, &game);
		mlx_loop(game.mlx_pointer);
		free_map(&game);
		clean_pics(&game);
		mlx_terminate(game.mlx_pointer);
	}
	else
		perror("Error \n Select valid map \n");
	return (0);
}
