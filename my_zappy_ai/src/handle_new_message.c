/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_message
*/

#include "zappy_ai.h"

void handle_new_message(client_t *client)
{
    char reply[BUFFER_SIZE + 1] = {0};
    ssize_t size = 0;

    if (!FD_ISSET(client->fd, &client->read_set)) {
        return;
    }
    size = read(client->fd, &reply, sizeof(reply) - 1);
    if (size == 0) {
        exit_client(0, "Server closed the connection.\n");
    } else if (size < 0) {
        exit_client(84, RED("Fail to read message.\n"));
    }
    if (size >= ((ssize_t) sizeof(reply)) - 1) {
        printf(RED("Incompatible reply from the server.\n"));
        return;
    }
    handle_server_reply(client, reply);
}
