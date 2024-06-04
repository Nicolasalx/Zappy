/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** spawn_resource
*/

#include "zappy_server.h"

static void count_ressource(game_t *game, int i, int count_spawn[NB_ITEM])
{
    for (int j = 0; j < game->world.size_y; ++j) {
        for (int k = 0; k < game->world.size_x; ++k) {
            count_spawn[i] += game->world.map[j][k].item[i];
        }
    }
}

static void add_new_ressource(server_t *server, int i,
    const int *count_spawn, const int *nb_spawn)
{
    int random_x = 0;
    int random_y = 0;

    if (nb_spawn[i] - count_spawn[i] > 0) {
        for (int j = 0; j < nb_spawn[i] - count_spawn[i]; ++j) {
            random_x = rand() % server->game.world.size_x;
            random_y = rand() % server->game.world.size_y;
            server->game.world.map[random_y][random_x].item[i] += 1;
            bct_reply(server, random_x, random_y);
        }
    }
}

void spawn_resource(server_t *server, game_t *game)
{
    int count_spawn[NB_ITEM] = {0};
    int nb_spawn[NB_ITEM] = {0};

    for (int i = 0; i < NB_ITEM; ++i) {
        nb_spawn[i] = round((game->world.size_x *
        game->world.size_y) * resource_density[i]);
        if (nb_spawn[i] <= 0) {
            nb_spawn[i] = 1;
        }
    }
    for (int i = 0; i < NB_ITEM; ++i) {
        count_ressource(game, i, count_spawn);
    }
    for (int i = 0; i < NB_ITEM; ++i) {
        add_new_ressource(server, i, count_spawn, nb_spawn);
    }
}
