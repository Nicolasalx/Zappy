/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct_reply
*/

#include "zappy_server.h"

void bct_reply(server_t *server, int x, int y)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer),
        "bct %d %d %d %d %d %d %d %d %d\n",
        x, y,
        server->game.world.map[y][x].item[FOOD],
        server->game.world.map[y][x].item[LINEMATE],
        server->game.world.map[y][x].item[DERAUMERE],
        server->game.world.map[y][x].item[SIBUR],
        server->game.world.map[y][x].item[MENDIANE],
        server->game.world.map[y][x].item[PHIRAS],
        server->game.world.map[y][x].item[THYSTAME]);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0
        && server->clients[i].player.is_graphic == true) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
