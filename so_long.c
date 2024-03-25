/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 10:13:28 by hwiemann         ###   ########.fr       */
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
	printf("game on \n");
	if(!(game->mlx_pointer = mlx_init((SSIZE * game->map.width),(SSIZE * game->map.height), "hello again", false)))
			perror("init error");

}

int	main(int argc, char **argv)
{
	t_program	game;
	char		*file;

	if(argc == 2)
	{
		file = argv[1];
		open_map(&game, file);
		game_on(&game); //initialisiert game pointer
		show_pics(&game); //initialisiert bilder
		map_init(&game);
		printf("Treasure to collect: %d \n", game.count.treasures);
		printf("Player in game: %d \n", game.count.player_count);
		check_map_possible(&game);
		if(check_path(&game, game.map.player.pos_x, game.map.player.pos_y, game.count.treasures) == 1)
			end_game(&game);

		for (int i = 0; i < game.map.height; i++) {
        for (int j = 0; j < game.map.width; j++) {
            printf("%c ", game.map.map[i][j]);
        }
        printf("\n");
    }
		mlx_loop_hook(game.mlx_pointer, &hook, &game);
		mlx_key_hook(game.mlx_pointer, &key_hook, &game);
		mlx_loop(game.mlx_pointer);
		clean_pics(&game);
		mlx_terminate(game.mlx_pointer);
	}
	else
		printf("nope");
	return(0);
}
