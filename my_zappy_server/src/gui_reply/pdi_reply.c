/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pdi_reply
*/

#include "zappy_server.h"

void pdi_reply(server_t *server, client_t *client)
{
    char buffer[100] = {0};

    for (int i = 0; i < MAX_CLIENT; i++) {
        if (client[i].fd != 0 && server->clients[i].is_graphic == true) {
            snprintf(buffer, sizeof(buffer), "pdi %d\n", client->player.id);
            send_msg_client(server->clients[i].fd, buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }
}
