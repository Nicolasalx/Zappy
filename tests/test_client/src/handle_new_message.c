/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_message
*/

#include "test_client.h"

void handle_new_message(client_t *client)
{
    char reply[BUFFER_SIZE + 1] = {0};
    ssize_t size = 0;

    if (!FD_ISSET(client->fd, &client->read_set)) {
        return;
    }
    size = read(client->fd, &reply, BUFFER_SIZE);
    if (size == 0) {
        exit_client(0, "Server closed the connection.\n");
    } else if (size == -1) {
        exit_client(84, RED("Fail to read message.\n"));
    }
    handle_server_reply(reply);
}
