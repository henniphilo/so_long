/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/20 11:06:03 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close()
{
	exit(0);
}


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
}
/*
void	game_init(t_program *game, char *map_file)
{
	//if(!(game->map = ft_calloc(sizeof(t_map), 1)))
	check_map_ber(map_file);
	get_map(game, );
	map_init(game);
	walls_check(game, game->map.map);
} */
void	game_on(t_program *game)
{
	if(!(game->mlx_pointer = mlx_init(WIN_WIDTH, WIN_HEIGHT, "hello again", true)))
			perror("init error");
}

int	main(int argc, char **argv)
{
	t_program	game;

	if(argc == 2)
	{
		printf("in");
		check_map_ber(argv[1]);
		game_on(&game);
		open_map(&game);
		mlx_loop(game.mlx_pointer);

	}
	else
		printf("nope");
	return(0);
}
/*
int	main(void)
{
	int		fd;
	char	*line = NULL;

	// Öffnen Sie eine Datei zum Lesen
	fd = open("test.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Fehler beim Öffnen der Datei");
		return (1);
	}

	// Lesen Sie die Datei Zeile für Zeile und geben Sie sie auf dem Bildschirm aus
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line); // Speicher freigeben, nachdem die Zeile ausgegeben wurde
	}

	// Schließen Sie die Datei
	close(fd);

	return (0);
} */

