/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pbc_reply
*/

#include "zappy_server.h"

void pbc_reply(server_t *server, client_t *client, char *message)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "pbc %d %s\n", client->player.orientation + 1, message);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic == true) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
