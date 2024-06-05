/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** set_command_reply
*/

#include "zappy_ai.h"

void set_command_reply(client_t *client, char *reply)
{
    char buffer[100] = {0};

    if (strcmp(reply, "ok") == 0) {
        snprintf(buffer, sizeof(buffer), "Broadcast -%d\n",
            client->player.last_item_taken);
        push_new_command(client, BROADCAST, buffer);
        client->player.inventory[client->player.last_item_taken] -= 1;
        client->shared_inventory[client->player.last_item_taken] -= 1;
    }
}
