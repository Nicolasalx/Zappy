/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_world
*/

#include "zappy_server.h"
#include <time.h>

static void create_egg(server_t *server)
{
    egg_t *new_egg = NULL;

    for (int i = 0; i < server->team_count; ++i) {
        for (int j = 0; j < server->team_list[i].remaining_place; ++j) {
            new_egg = my_calloc(sizeof(egg_t));
            new_egg->nb = server->egg_count;
            ++server->egg_count;
            new_egg->pos_x = rand() % server->world.size_x;
            new_egg->pos_y = rand() % server->world.size_y;
            append_node(&server->team_list[i].egg_list, create_node(new_egg));
        }
    }
}

void create_world(server_t *server)
{
    srand(time(NULL));
    server->world.map = my_calloc(sizeof(tile_t *) * (server->world.size_y + 1));
    for (int i = 0; i < server->world.size_y; ++i) {
        server->world.map[i] = my_calloc(sizeof(tile_t) * server->world.size_x);
    }
    spawn_resource(server);
    create_egg(server);
}
