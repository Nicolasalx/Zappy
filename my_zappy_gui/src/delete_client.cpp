/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** delete_client
*/

#include "zappy_gui.hpp"
#include <dlfcn.h>

void delete_client(client_t *client)
{
    if (client == NULL) {
        return;
    }
    if (client->fd > 0) {
        close(client->fd);
    }
}
