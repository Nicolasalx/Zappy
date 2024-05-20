/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** send_cmd_to_server
*/

#include "zappy_gui.hpp"
#include <iostream>

void send_cmd_to_server(client_t *client, char *cmd)
{
    if (FD_ISSET(client->fd, &client->write_set)) {
        if (send(client->fd, cmd, strlen(cmd), 0) == -1) {
            std::cout << "Fail to send message to server.\n";
        }
    }
}
