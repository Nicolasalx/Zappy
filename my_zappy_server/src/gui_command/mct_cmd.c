/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** mct_cmd
*/

#include "zappy_server.h"

void mct_cmd(int, char **, client_t *client, server_t *server)
{
    char buffer[100] = {0};

    for (int i = 0; i < server->game.world.size_y; ++i) {
        for (int j = 0; j < server->game.world.size_x; ++j) {
            snprintf(buffer, sizeof(buffer),
                "bct %d %d %d %d %d %d %d %d %d\n",
                j, i,
                server->game.world.map[i][j].item[FOOD],
                server->game.world.map[i][j].item[LINEMATE],
                server->game.world.map[i][j].item[DERAUMERE],
                server->game.world.map[i][j].item[SIBUR],
                server->game.world.map[i][j].item[MENDIANE],
                server->game.world.map[i][j].item[PHIRAS],
                server->game.world.map[i][j].item[THYSTAME]);
            send_msg_client(client->fd, buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }
}
