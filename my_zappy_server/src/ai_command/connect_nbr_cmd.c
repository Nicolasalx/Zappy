/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** connect_nbr_cmd
*/

#include "zappy_server.h"

void connect_nbr_cmd(char *, client_t *client, server_t *)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "%d\n",
        client->player.team->remaining_spot);
    send_msg_client(client->fd, buffer);
}
