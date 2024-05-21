/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_player
*/

#include "zappy_server.h"

void init_player(client_t *client)
{
    client->player.inventory[FOOD] = 10;
}
