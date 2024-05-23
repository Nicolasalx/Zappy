/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_world
*/

#include "zappy_server.h"
#include <time.h>

void create_world(server_t *server)
{
    srand(time(NULL));
    server->world.map = my_calloc(sizeof(tile_t *) * (server->world.size_y + 1));
    for (int i = 0; i < server->world.size_y; ++i) {
        server->world.map[i] = my_calloc(sizeof(tile_t) * server->world.size_x);
    }
    spawn_resource(server);
}
