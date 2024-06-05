/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_client
*/

#include "zappy_ai.h"

void launch_client(client_t *client)
{
    int max_fd = 0;

    while (true) {
        init_client_set(client, &max_fd);
        monitor_input(client, max_fd);
        handle_new_message(client);
    }
}
