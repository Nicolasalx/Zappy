/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** lauch_server
*/

#include "zappy_server.h"
#include <signal.h>

void handle_active_client(server_t *server)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 &&
        FD_ISSET(server->clients[i].fd, &server->read_set)) {
            get_client_input(server, &server->clients[i]);
        }
    }
}

void close_server(int)
{
    delete_server(get_server(NULL));
    my_exit(0);
}

void lauch_server(server_t *server)
{
    int max_fd = server->fd;

    signal(SIGINT, close_server);
    while (true) {
        init_server_set(server, &max_fd);
        monitor_client(server, max_fd);
        handle_new_connection(server);
        handle_server_input(server);
        handle_active_client(server);
        if (!server->opt.end_game && !server->opt.pause_game) {
            update_resource(server);
            update_simulation(server);
        }
    }
}
