/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** get_map_size
*/

#include "zappy_server.h"

static void get_width(const char **argv, game_t *game, int i)
{
    if (strcmp(argv[i], args[1]) == 0) {
        if (argv[i + 1] == NULL) {
            my_error("Error: Width must be specified", 84);
        }
        if (!my_str_only_cont(argv[i + 1], "0123456789")) {
            my_error("Error: Width must be a number", 84);
        }
        game->world.size_x = atoi(argv[i + 1]);
    }
}

static void get_height(const char **argv, game_t *game, int i)
{
    if (strcmp(argv[i], args[2]) == 0) {
        if (argv[i + 1] == NULL) {
            my_error("Error: Height must be specified", 84);
        }
        if (!my_str_only_cont(argv[i + 1], "0123456789")) {
            my_error("Error: Height must be a number", 84);
        }
        game->world.size_y = atoi(argv[i + 1]);
    }
}

void get_map_size(const char **argv, game_t *game, int i)
{
    get_width(argv, game, i);
    get_height(argv, game, i);
}
