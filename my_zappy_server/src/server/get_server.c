/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** get_server
*/

#include "zappy_server.h"

server_t *get_server(server_t *server)
{
    static server_t *server_ptr = NULL;

    if (server != NULL) {
        server_ptr = server;
    }
    return server_ptr;
}
