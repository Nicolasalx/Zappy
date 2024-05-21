/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** msc_cmd
*/

#include "zappy_server.h"

void msz_cmd(int nb_args, char **argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    snprintf(buffer, sizeof(buffer), "msz %d %d\n", server->world.size_x, server->world.size_y);
    send_msg_client(client->fd, buffer);
}