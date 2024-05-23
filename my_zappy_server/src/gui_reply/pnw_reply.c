/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pnw_reply
*/

#include "zappy_server.h"

void pnw_reply(server_t *server, client_t *client)
{
    char buffer[100] = {0};

    for (int i = 0; i < MAX_CLIENT; i++) {
        if (client[i].fd != 0 && server->clients[i].is_graphic == true) {
            snprintf(buffer, sizeof(buffer), "pnw %d %d %d %d %d %s\n", client->player.id, client->player.pos_x, client->player.pos_y, client->player.orientation + 1, client->player.level, client->player.team->name);
            send_msg_client(server->clients[i].fd, buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }
}