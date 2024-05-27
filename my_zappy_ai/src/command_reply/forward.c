/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** forward
*/

#include "zappy_ai.h"

void forward_command(client_t *client, char *reply)
{
    printf("Forward\n");
    client->last_cmd = FORWARD;
    push_new_command(client, BROADCAST, "Forward\n");
}
