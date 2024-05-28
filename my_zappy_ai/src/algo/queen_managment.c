/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** queen_management
*/

#include "zappy_ai.h"

void queen_get_inventory(client_t *client)
{
    push_new_command(client, INVENTORY, "Inventory\n");
}

void queen_eat(client_t *client)
{
    if (client->player.inventory[FOOD] < 10) {
        push_new_command(client, TAKE, "Take food\n");
        client->instruction_index -= 2;
    }
}

void queen_incantation(client_t *client)
{
    push_new_command(client, INCANTATION, "Incantation\n");
}

void queen_management(client_t *client)
{
    push_new_command(client, BROADCAST, "I'm your queen");
    push_new_command(client, INVENTORY, "Inventory\n");
    if (client->player.inventory[FOOD] < 10) {
        push_new_command(client, TAKE, "Take food\n");
        push_new_command(client, TAKE, "Take food\n");
        push_new_command(client, TAKE, "Take food\n");
        push_new_command(client, TAKE, "Take food\n");
        push_new_command(client, TAKE, "Take food\n");
    }
    push_new_command(client, INCANTATION, "Incantation\n");
}
