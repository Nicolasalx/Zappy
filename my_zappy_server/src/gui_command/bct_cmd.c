/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct_cmd
*/

#include "zappy_server.h"

static void print_map(server_t *server, client_t *client, int x, int y)
{
    char buffer[100] = {0};

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

void bct_cmd(int, char **argv, client_t *client, server_t *server)
{
    int x = atoi(argv[0]);
    int y = atoi(argv[1]);

    if (x < 0 || x >= server->world.size_x || y < 0
    || y >= server->world.size_y ||
    (!my_str_only_cont(argv[0], "0123456789")
    || !my_str_only_cont(argv[1], "0123456789"))) {
        send_msg_client(client->fd, "sbp\n");
        return;
    }
    print_map(server, client, x, y);
}
