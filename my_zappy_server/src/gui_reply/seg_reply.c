/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** seg_reply
*/

#include "zappy_server.h"

void seg_reply(server_t *server, client_t *client)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "seg %s\n", client->player.team->name);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic == true) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
