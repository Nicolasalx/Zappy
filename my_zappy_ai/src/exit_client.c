/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** exit_client
*/

#include "zappy_ai.h"

void exit_client(int exit_value, const char *message)
{
    if (message != NULL) {
        my_putstr(message);
    }
    delete_client(get_client(NULL));
    my_exit(exit_value);
}

