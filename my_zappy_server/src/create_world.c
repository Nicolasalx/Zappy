/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_world
*/

#include "zappy_server.h"

static void create_egg(game_t *game)
{
    egg_t *new_egg = NULL;

    for (int i = 0; i < game->team_count; ++i) {
        for (int j = 0; j < game->team_list[i].remaining_spot; ++j) {
            new_egg = my_calloc(sizeof(egg_t));
            new_egg->nb = game->egg_count;
            ++game->egg_count;
            new_egg->pos_x = rand() % game->world.size_x;
            new_egg->pos_y = rand() % game->world.size_y;
            append_node(&game->team_list[i].egg_list, create_node(new_egg));
        }
    }
}

void create_world(server_t *server)
{
    srand(time(NULL));
    server->game.world.map = my_calloc(sizeof(tile_t *) *
        (server->game.world.size_y + 1));
    for (int i = 0; i < server->game.world.size_y; ++i) {
        server->game.world.map[i] = my_calloc(sizeof(tile_t) *
        server->game.world.size_x);
    }
    spawn_resource(server, &server->game);
    create_egg(&server->game);
}
