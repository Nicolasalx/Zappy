/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** sgt_cmd
*/

#include "zappy_server.h"

void sgt_cmd(int, char **, client_t *client, server_t *server)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "sgt %d\n", (int)server->opt.freq);
    send_msg_client(client->fd, buffer);
}
