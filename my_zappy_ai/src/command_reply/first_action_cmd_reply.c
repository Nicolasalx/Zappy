/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** first_action_cmd_reply
*/

#include "zappy_ai.h"

void send_command_broad_cast(client_t *client, const char *text)
{
    char result[250] = {0};

    snprintf(result, sizeof(result), "Broadcast |%s|%d|%s|\n",
        client->player.team_name, client->fd, text);
    push_new_command(client, BROADCAST, result);
}

void broadcast_command(client_t *, char *reply)
{
    printf("%s\n", reply);
}
