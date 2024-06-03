/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** send_cmd_to_server
*/

#include "test_client.h"

void send_cmd_to_server(client_t *client, char *cmd)
{
    if (FD_ISSET(client->fd, &client->write_set)) {
        if (send(client->fd, cmd, strlen(cmd), 0) == -1) {
            my_putstr(RED("Fail to send message to server.\n"));
        } else {
            printf("send: \"%s\"\n", cmd);
        }
    }
}
