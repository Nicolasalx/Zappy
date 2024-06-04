/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** edi_reply
*/

#include "zappy_server.h"

void edi_reply(server_t *server, client_t *, egg_t *new_egg)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "edi %d\n", new_egg->nb);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0
        && server->clients[i].player.is_graphic == true) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
