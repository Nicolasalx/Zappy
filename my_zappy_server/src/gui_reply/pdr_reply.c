/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pdr_reply
*/

#include "zappy_server.h"

void pdr_reply(server_t *server, client_t *client, int nb_resource)
{
    char buffer[100] = {0};

    for (int i = 0; i < MAX_CLIENT; i++) {
        if (client[i].fd != 0 && server->clients[i].is_graphic == true) {
            snprintf(buffer, sizeof(buffer), "pdr %d %d\n", client->player.id, nb_resource);
        }
    }
}
