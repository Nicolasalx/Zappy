/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** delete_server
*/

#include "zappy_server.h"
#include <dlfcn.h>

void delete_server(server_t *server)
{
    fflush(NULL);
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        remove_client(&server->clients[i]);
    }
    close(server->fd);
}
