/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** queen_management
*/

#include "zappy_ai.h"

void farmer_management(client_t *client)
{
    if (client->player.inventory[FOOD] < 50) {
        push_new_command(client, TAKE, "Take food\n");
        push_new_command(client, INVENTORY, "Inventory\n");
    } else {
        if (client->player.inventory[FOOD] < 10) {
            push_new_command(client, SET, "Look\n");
        }
    }
}