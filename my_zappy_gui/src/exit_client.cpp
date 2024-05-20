/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** exit_client
*/

#include "zappy_gui.hpp"
#include <iostream>

void exit_client(int exit_value, const char *message)
{
    if (message != NULL) {
        std::cerr << message << '\n';
    }
    delete_client(get_client(NULL));
    exit(exit_value);
}
