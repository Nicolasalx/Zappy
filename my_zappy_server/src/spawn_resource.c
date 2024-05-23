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
    int count_spawn[NB_ITEM] = {0};
    int nb_spawn[NB_ITEM];

    for (int i = 0; i < NB_ITEM; ++i) {
        nb_spawn[i] = round((server->world.size_x * server->world.size_y) * resource_density[i]);
        if (nb_spawn[i] <= 0) {
            nb_spawn[i] = 1;
        }
    }
    for (int y = 0; y < server->world.size_y; ++y) {
        for (int x = 0; x < server->world.size_x; ++x) {
            for (int k = 0; k < NB_ITEM; ++k) {
                count_spawn[k] += server->world.map[y][x].item[k];
            }
        }
    }
    for (int i = 0; i < NB_ITEM; ++i) {
        if (nb_spawn[i] - count_spawn[i] > 0) {
            for (int j = 0; j < nb_spawn[i] - count_spawn[i]; ++j) {
                ++server->world.map[rand() % server->world.size_y][rand() % server->world.size_x].item[i];
            }
        }
    }
}
