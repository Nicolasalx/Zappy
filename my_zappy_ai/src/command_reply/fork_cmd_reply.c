/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** fork_cmd_reply
*/

#include "zappy_ai.h"

void fork_command_reply(client_t *client, char *reply)
{
    if (strcmp(reply, "ok") == 0) {
        client->remaining_spots += 1;
    }
}
