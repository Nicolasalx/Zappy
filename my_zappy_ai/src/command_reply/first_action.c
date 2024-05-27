/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** first_action
*/

#include "zappy_ai.h"

void first_action(client_t *client, char *reply)
{
    client->last_cmd = FORWARD;
    send_cmd_to_server(client, "Forward\n");
}
