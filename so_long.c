/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 17:59:30 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close()
{
	exit(0);
}

static void	hook(void *ptr)
{
	t_program	*game;

	game = ptr;
}

void	game_on(t_program *game)
{
	printf("Game On\n Collect all blue tiles \n");
	if(!(game->mlx_pointer = mlx_init((SSIZE * game->map.width),(SSIZE * game->map.height), "hello again", false)))
			perror("Error \n init error");

}

int	main(int argc, char **argv)
{
	t_program	game;
	char		*file;

	if(argc == 2)
	{
		file = argv[1];
		open_map(&game, file);
		game_on(&game);
		show_pics(&game);
		map_init(&game);
		check_correct_CPE(&game);
		if(check_path(&game, game.map.player.pos_x, game.map.player.pos_y, game.count.treasures) == 1)
		{
			perror("Error \n fd path not valid \n");
			end_game(&game);
		}
		mlx_loop_hook(game.mlx_pointer, &hook, &game);
		mlx_key_hook(game.mlx_pointer, &key_hook, &game);
		mlx_loop(game.mlx_pointer);
		clean_pics(&game);
		mlx_terminate(game.mlx_pointer);
	}
	else
		perror("Error \n Select valid map \n");
	return(0);
}
