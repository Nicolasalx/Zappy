/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** exit_client
*/

#include "zappy_ai.h"

void exit_client(client_t *client, int exit_value, const char *message)
{
    if (message != NULL) {
        my_putstr(message);
    }
    if (exit_value) {
        pthread_mutex_lock(&get_thread_list(NULL)->mutex);
        get_thread_list(NULL)->exit_code = exit_value;
        pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
    }
    delete_client(client);
    remove_thread_from_list();
    pthread_exit(NULL);
}
