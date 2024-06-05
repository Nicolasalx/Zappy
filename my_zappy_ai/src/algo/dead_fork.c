/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** dead_fork
*/

#include "zappy_ai.h"

void dead_fork(client_t *client)
{
    if (!client->player.try_die) {
        if (client->remaining_spots > 0
        && client->player.content_look[0][TILE_PLAYER] < 2
        && client->player.content_look[0][TILE_FOOD] < 5) {
            exit_client(client, 0, NULL);
        }
        client->player.try_die = true;
    }
    push_new_command(client, FORK, "Fork\n");
}

void wait_end_fork(client_t *client)
{
    create_new_ai(client->port,
        &client->server_address.sin_addr, client->player.team_name);
    for (size_t i = 0; i < 10; ++i) {
        push_new_command(client, SET, "Set food\n");
    }
}
