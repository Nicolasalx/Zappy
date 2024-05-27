/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look
*/

#include "zappy_ai.h"

void forward(client_t *client, char *reply)
{
    printf("FORWARD\n");
    client->last_cmd = FORWARD;
    send_cmd_to_server(client, "Forward\n");
}
