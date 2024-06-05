/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_client_set
*/

#include "zappy_ai.h"
#include <sys/time.h>

void init_client_set(client_t *client, int *max_fd)
{
    FD_ZERO(&client->read_set);
    FD_SET(client->fd, &client->read_set);
    FD_ZERO(&client->write_set);
    FD_SET(client->fd, &client->write_set);
    *max_fd = client->fd;
}

void monitor_input(client_t *client, int max_fd)
{
    struct timeval timeout = {.tv_sec = 1, .tv_usec = 1000000};

    if (select(max_fd + 1, &client->read_set,
        &client->write_set, NULL, &timeout) == -1) {
        exit_client(client, 84, RED("Select fail.\n"));
    }
}
