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
    int nb_spawn[NB_ITEM] = {0};

    for (int i = 0; i < NB_ITEM; ++i) {
        nb_spawn[i] = round((server->world.size_x * server->world.size_y) * resource_density[i]);
        if (nb_spawn[i] <= 0) {
            nb_spawn[i] = 1;
        }
    }
    for (int i = 0; i < server->world.size_y; ++i) {
        for (int j = 0; j < server->world.size_x; ++j) {
            for (int k = 0; k < NB_ITEM; ++k) {
                count_spawn[k] += server->world.map[i][j].item[k];
            }
        }
    }
    for (int i = 0; i < NB_ITEM; ++i) {
        if (nb_spawn[i] - count_spawn[i] > 0) {
            for (int j = 0; j < nb_spawn[i] - count_spawn[i]; ++j) {
                int random_x = rand() % server->world.size_x;
                int random_y = rand() % server->world.size_y;
                ++server->world.map[random_y][random_x].item[i];
                bct_reply(server, random_x, random_y);
            }
        }
    }
}
