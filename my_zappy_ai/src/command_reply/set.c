/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** set
*/

#include "zappy_ai.h"

void set_command(client_t *client, char *reply)
{
    printf("Set\n");
    client->last_cmd = SET;
}
