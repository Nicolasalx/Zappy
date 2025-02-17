/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_client_set
*/

#include "test_client.h"

void init_client_set(client_t *client, int *max_fd)
{
    FD_ZERO(&client->read_set);
    FD_SET(STDIN_FILENO, &client->read_set);
    FD_SET(client->fd, &client->read_set);
    FD_ZERO(&client->write_set);
    FD_SET(client->fd, &client->write_set);
    *max_fd = client->fd;
}

void monitor_input(client_t *client, int max_fd)
{
    if (select(max_fd + 1, &client->read_set,
        &client->write_set, NULL, NULL) == -1) {
        exit_client(84, RED("Select fail.\n"));
    }
}
