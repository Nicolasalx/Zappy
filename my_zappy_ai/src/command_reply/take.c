/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** take
*/

#include "zappy_ai.h"

void take_reply(client_t *client, char *reply)
{
    printf("Take\n");
    client->last_cmd = TAKE;
}
