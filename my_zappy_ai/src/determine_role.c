/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** determine_role
*/

#include "zappy_ai.h"

void get_nb_food(client_t *client)
{
    push_new_command(client, LOOK, "Look\n");
}

static void determine_role_helper(client_t *client)
{
    if (client->player.content_look[0][TILE_PLAYER] > 10
    && rand() % 51 != 50) {
        if ((client->player.content_look[0][TILE_LINEMATE] < 20
        || client->player.content_look[0][TILE_DERAUMERE] < 10
        || client->player.content_look[0][TILE_SIBUR] < 10
        || client->player.content_look[0][TILE_MENDIANE] < 10
        || client->player.content_look[0][TILE_PHIRAS] < 10
        || client->player.content_look[0][TILE_THYSTAME] < 10)
        && rand() % 10 <= 5) {
            client->strategy = FARMER;
        } else {
            client->strategy = KILL_IT_SELF;
        }
    } else {
        client->strategy = QUEEN;
    }
}

void determine_role(client_t *client)
{
    client->instruction_index = 0;
    if (client->player.content_look[0][TILE_FOOD] < 75) {
        client->strategy = DEAD_FORK;
        push_new_command(client, CONNECT_NBR, "Connect_nbr\n");
        return;
    }
    determine_role_helper(client);
    push_new_command(client, CONNECT_NBR, "Connect_nbr\n");
}
