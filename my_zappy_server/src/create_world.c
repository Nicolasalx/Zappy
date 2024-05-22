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
    server->world.map = (tile_t **) malloc_gn_board(server->world.size_y,
        server->world.size_x, sizeof(**server->world.map));
    spawn_resource(server);
}
