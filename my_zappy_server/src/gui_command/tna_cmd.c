/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tna_cmd
*/

#include "zappy_server.h"

void tna_cmd(int, char **, client_t *client, server_t *server)
{
    char buffer[100] = {0};

    for (int i = 0; i < server->team_count; i++) {
        snprintf(buffer, sizeof(buffer), "tna %s\n", server->team_list[i].name);
        send_msg_client(client->fd, buffer);
    }
}
