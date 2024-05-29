/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** kill_it_self
*/

#include "zappy_ai.h"

void kill_it_self(client_t *client)
{
    push_new_command(client, SET, "Set food\n");
}
