/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** monitor_client
*/

#include "zappy_server.h"

void monitor_client(server_t *server, int max_fd)
{
    int nb_fd = select(max_fd + 1,
        &server->read_set, &server->write_set, NULL, NULL);

    if (nb_fd == -1) {
        printf("Select fail\n");
        delete_server(server);
        my_exit(84);
    }
}
