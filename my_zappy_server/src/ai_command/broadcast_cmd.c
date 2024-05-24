/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_cmd
*/

#include "zappy_server.h"

void broadcast_cmd(char *argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    char *message = strtok(argv, "\n");

    snprintf(buffer, sizeof(buffer), "message %d, %s\n", client->player.orientation, message);
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic != true && server->clients[i].player.team
            && client->player.id != server->clients[i].player.id) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
    pbc_reply(server, client, message);
}
