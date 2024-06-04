/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** ebo_reply
*/

#include "zappy_server.h"

void ebo_reply(server_t *server, egg_t *new_egg)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "ebo %d\n", new_egg->nb);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0
        && server->clients[i].player.is_graphic == true) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
