/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** spawn_resource
*/

#include "zappy_server.h"
#include <math.h>

void spawn_resource(server_t *server)
{
    for (int i = 0; i < NB_ITEM; ++i) {
        int nb_spawn = round((server->world.size_x * server->world.size_y) * resource_density[i]);
        if (nb_spawn <= 0) {
            nb_spawn = 1;
        }
        for (int j = 0; j < nb_spawn; ++j) {
            ++server->world.map[rand() % server->world.size_y][rand() % server->world.size_x].item[i];
        }
    }
}
