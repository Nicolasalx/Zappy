/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_client
*/

#include "zappy_ai.h"
#include <signal.h>

void close_client(int)
{
    exit_client(0, NULL);
}

void launch_client(client_t *client)
{
    int max_fd = 0;

    signal(SIGINT, close_client);
    while (true) {
        init_client_set(client, &max_fd);
        monitor_input(client, max_fd);
        handle_new_message(client);
    }
}
