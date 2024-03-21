/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/21 11:48:05 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close()
{
	exit(0);
}

/*
t_program	window()
{
	t_program		ptr; // all stuff is stored here
	// mlx_texture_t 	*texture;
	// mlx_image_t		*image;

	if(!(ptr.mlx_pointer = mlx_init(WIN_WIDTH, WIN_HEIGHT, "hello again", true)))
		exit(1);

	// if(!(texture = mlx_load_png("Wall.png")))
	// 	exit(1);

	// if(!(image = mlx_texture_to_image(ptr.mlx_pointer, texture)))
	// 	exit(1);

	// if(!(looking_good(ptr.mlx_pointer)))
	// if(!(looking_good(&ptr)))
	// 	perror("nothing looks good");

	show_pics(&ptr);

	if(mlx_image_to_window(ptr.mlx_pointer, ptr.img.treasure, 0, 0) < 0)
		exit(1);

	mlx_loop(ptr.mlx_pointer);

	return(ptr);
} */

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
		map_init(&game); //
		key_hook( , game);
		mlx_loop(game.mlx_pointer);
		clean_pics(&game);
		mlx_terminate(game.mlx_pointer);
	}
	else
		printf("nope");
	return(0);
}




