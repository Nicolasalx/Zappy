/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** take_cmd_reply
*/

#include "zappy_ai.h"

void take_command_reply(client_t *client, char *reply)
{
    if (strcmp(reply, "ok") == 0) {
        client->player.inventory[client->player.last_item_taken] += 1;
        client->shared_inventory[client->player.last_item_taken] += 1;
    }
}
