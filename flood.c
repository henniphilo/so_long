/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:24:46 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/25 10:12:08 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

#define MAP_WIDTH  9
#define MAP_HEIGHT 8

typedef struct {
    char map[MAP_HEIGHT][MAP_WIDTH];
    int width;
    int height;
} t_map;

typedef struct {
    t_map map;
} t_program;

int flood_path(t_program *game, int x, int y, int c) {
    t_map *map = &game->map;

    if (x < 0 || x >= map->width || y < 0 || y >= map->height ||
        map->map[y][x] == 'O' || map->map[y][x] == '1' ||
        map->map[y][x] == 'c' || map->map[y][x] == 'E') {
        if (map->map[y][x] == 'E')
            return 1;
        return 0;
    }

    if (map->map[y][x] == 'C') {
        c--;
        map->map[y][x] = 'c';
    } else if (map->map[y][x] == '0') {
        map->map[y][x] = 'O';
    }
    flood_path(game, x, y + 1, c);
    flood_path(game, x, y - 1, c);
    flood_path(game, x + 1, y, c);
    flood_path(game, x - 1, y, c);
    return 0;
}

int check_path(t_program *game, int x, int y, int c) {
    flood_path(game, x, y, c);

    for (int y = 0; y < game->map.height; y++) {
        for (int x = 0; x < game->map.width; x++) {
            if (game->map.map[y][x] != 'c' && game->map.map[y][x] != 'P'
                && game->map.map[y][x] != 'O' && game->map.map[y][x] != 'E'
                && game->map.map[y][x] != '1')
                return 1;
            else {
                if (game->map.map[y][x] == 'c')
                    game->map.map[y][x] = 'C';
                else if (game->map.map[y][x] == 'O')
                    game->map.map[y][x] = '0';
            }
        }
    }
    return 0;
}

int main() {
    char initial_map[MAP_HEIGHT][MAP_WIDTH] = {
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        {'1', '1', '0', '0', 'C', '1', '1', '1', '1'},
        {'1', '0', '1', 'P', '0', '0', '0', '1', '1'},
        {'1', 'C', '1', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', 'E', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', 'C', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

    t_program game;
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            game.map.map[i][j] = initial_map[i][j];
        }
    }
    game.map.height = MAP_HEIGHT;
    game.map.width = MAP_WIDTH;

    int c = 3; // Anzahl der möglichen Züge
    if (check_path(&game, 3, 2, c) == 0) {
        printf("Valider Pfad gefunden!\n");
    } else {
        printf("Kein valider Pfad gefunden!\n");
    }

    // Ausgabe der überprüften Karte
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", game.map.map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/
