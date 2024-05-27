/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_connection
*/

#include "zappy_server.h"

void handle_new_connection(server_t *server)
{
    socklen_t addr_len = sizeof(server->address);
    int new_client = 0;
    client_t client = {0};

    if (FD_ISSET(server->fd, &server->read_set)) {
        new_client = accept(server->fd,
        (struct sockaddr *) &server->address, &addr_len);
        if (new_client == -1) {
            delete_server(server);
            my_exit(84);
        }
        printf(CYAN("New client connected")"\n");
        client.fd = new_client;
        handle_new_player(server, &client);
        add_client(server, &client);
    }
}
