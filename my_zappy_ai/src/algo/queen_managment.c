/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** queen_management
*/

#include "zappy_ai.h"

void queen_management(client_t *client)
{
    push_new_command(client, INVENTORY, "Inventory\n");
    if (client->player.inventory[LINEMATE] > 5) {
        push_new_command(client, INCANTATION, "Incantation\n");
    }
}