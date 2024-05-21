/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** plv_cmd
*/

#include "zappy_server.h"

void plv_cmd(int, char **argv, client_t *client, server_t *)
{
    char buffer[100] = {0};
    int id = atoi(argv[0]);

    snprintf(buffer, sizeof(buffer), "plv #%d %d\n", id, client[id].player.level);
    send_msg_client(client->fd, buffer);
}