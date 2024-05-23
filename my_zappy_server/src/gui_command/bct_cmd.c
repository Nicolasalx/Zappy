/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct_cmd
*/

#include "zappy_server.h"

void bct_cmd(int, char **args, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    int x = atoi(args[0]);
    int y = atoi(args[1]);

    if (x < 0 || x >= server->world.size_x || y < 0 || y >= server->world.size_y) {
        send_msg_client(client->fd, "sbp\n");
        return;
    }
    snprintf(buffer, sizeof(buffer),
        "bct %d %d %d %d %d %d %d %d %d\n",
        x, y,
        server->world.map[y][x].item[FOOD],
        server->world.map[y][x].item[LINEMATE],
        server->world.map[y][x].item[DERAUMERE],
        server->world.map[y][x].item[SIBUR],
        server->world.map[y][x].item[MENDIANE],
        server->world.map[y][x].item[PHIRAS],
        server->world.map[y][x].item[THYSTAME]);
    send_msg_client(client->fd, buffer);
}