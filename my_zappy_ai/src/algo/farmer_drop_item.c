/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** farmer_drop_item
*/

#include "zappy_ai.h"

void farmer_drop_items(client_t *client)
{
    char buffer[100] = {0};

    for (int i = NB_ITEM - 1; i >= 0; --i) {
        if (client->player.inventory[i] > 0) {
            snprintf(buffer, sizeof(buffer), "Set %s\n", object_list[i]);
            push_new_command(client, SET, buffer);
            memset(buffer, 0, sizeof(buffer));
            client->player.inventory[i]--;
            break;
        }
    }
    client->instruction_index -= 1;
}
