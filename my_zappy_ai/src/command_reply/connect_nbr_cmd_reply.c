/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** connect_nbr_cmd_reply
*/

#include "zappy_ai.h"

void connect_nbr_command_reply(client_t *client, char *reply)
{
    client->remaining_spots = atoi(reply);
}
