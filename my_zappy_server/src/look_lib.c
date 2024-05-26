/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look_direction
*/

#include "zappy_server.h"

void append_with_space_if_needed(char *buff, const char *str, bool *first)
{
    if (!(*first)) {
        strcat(buff, " ");
    }
    strcat(buff, str);
    *first = false;
}

void get_item_str(char *buff, int x, int y, server_t *server)
{
    bool first = true;

    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0
            && server->clients[i].player.pos_x == x
            && server->clients[i].player.pos_y == y) {
            append_with_space_if_needed(buff, "player", &first);
        }
    }
    for (int i = 0; i < NB_ITEM; ++i) {
        for (int j = 0; j < server->world.map[y][x].item[i]; ++j) {
            append_with_space_if_needed(buff, object_list[i], &first);
        }
    }
}

void append_with_coma_if_needed_x(client_t *client, char *buff, int x, int i)
{
    if (x < (client->player.pos_x + i) || i < client->player.level) {
        strcat(buff, ",");
    }
}

void append_with_coma_if_needed_y(client_t *client, char *buff, int y, int i)
{
    if (y < (client->player.pos_y + i) || i < client->player.level) {
        strcat(buff, ",");
    }
}
