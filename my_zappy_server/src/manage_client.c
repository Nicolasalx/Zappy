/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** manage_client
*/

#include "zappy_server.h"
#include <stdarg.h>

void add_client(server_t *server, client_t *client)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd == 0) {
            memcpy(&server->clients[i], client, sizeof(client_t));
            break;
        }
    }
}

void remove_client(client_t *client)
{
    if (client->player.team) {
        client->player.team->player_max -= 1;
        client->player.team->remaining_spot += 1;
    }
    my_free(client->cmd_buffer);
    if (client->fd != 0) {
        close(client->fd);
    }
    memset(client, 0, sizeof(client_t));
}
