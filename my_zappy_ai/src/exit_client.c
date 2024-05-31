/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** exit_client
*/

#include "zappy_ai.h"

void exit_client(client_t *client, int exit_value, const char *message)
{
    (void) exit_value;

    if (message != NULL) {
        my_putstr(message);
    }
    delete_client(client);
    remove_thread_from_list();
    pthread_exit(NULL);
}
