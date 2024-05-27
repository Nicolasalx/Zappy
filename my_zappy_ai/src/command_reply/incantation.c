/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation
*/

#include "zappy_ai.h"

void incantation_command(client_t *client, char *reply)
{
    printf("Incantation\n");
    client->last_cmd = INCANTATION;
}
