/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_message
*/

#include "zappy_gui.hpp"

void handle_new_message(client_t *client)
{
    char reply_data[BUFFER_SIZE] = {0};
    ssize_t size = 0;

    if (!FD_ISSET(client->fd, &client->read_set)) {
        return;
    }
    size = read(client->fd, &reply_data, sizeof(reply_data));
    if (size == 0) {
        exit_client(0, "Server closed the connection.\n");
    } else if (size == -1) {
        exit_client(84, "Fail to read message.\n");
    }
    if (size >= BUFFER_SIZE) {
        printf("Incompatible reply from the server.\n");
        return;
    }
    handle_server_reply(reply_data);
}
