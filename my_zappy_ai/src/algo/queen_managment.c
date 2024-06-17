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
    push_new_command(client, TAKE, "Take food\n");
}

void queen_check_nb_food(client_t *client)
{
    push_new_command(client, LOOK, "Look\n");
}

void queen_create_child(client_t *client)
{
    push_new_command(client, FORK, "Fork\n");
}

void queen_incantation(client_t *client)
{
    push_new_command(client, BROADCAST, "I'm here\n");
    push_new_command(client, INCANTATION, "Incantation\n");
    push_new_command(client, TAKE, "Take food\n");
    push_new_command(client, TAKE, "Take food\n");
    push_new_command(client, TAKE, "Take food\n");
    if (client->player.content_look[0][TILE_FOOD] < 50
    || client->player.content_look[0][TILE_PLAYER] < 4) {
        create_new_ai(client->port,
            &client->server_address.sin_addr, client->player.team_name);
    }
    if (client->player.content_look[0][TILE_FOOD] < 20) {
        create_new_ai(client->port,
            &client->server_address.sin_addr, client->player.team_name);
    }
}
