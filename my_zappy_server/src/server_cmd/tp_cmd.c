/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tp_cmd
*/

#include "zappy_server.h"

static bool tp_error_management(char **argv, server_t *server)
{
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int o = atoi(argv[3]);

    if (!my_str_only_cont(argv[0], "0123456789")
    || !my_str_only_cont(argv[1], "0123456789")
    || !my_str_only_cont(argv[2], "0123456789")
    || !my_str_only_cont(argv[3], "0123456789")
    || x < 0 || x >= server->world.size_x
    || y < 0 || y >= server->world.size_y
    || o < 1 || o > 4) {
        printf("Error: invalid argument\n");
        return true;
    }
    return false;
}

void tp_cmd(int, char **argv, server_t *server)
{
    int id = atoi(argv[0]);
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int o = atoi(argv[3]);

    if (tp_error_management(argv, server))
        return;
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].player.id == id
        && server->clients[i].is_graphic == false
        && server->clients[i].player.team) {
            server->clients[i].player.pos_x = x;
            server->clients[i].player.pos_y = y;
            server->clients[i].player.orientation = o - 1;
            printf("Player %d has been teleported to %d %d %d\n", id, x, y, o);
            ppo_reply(server, &server->clients[i]);
            return;
        }
    }
    printf("Error: client not found\n");
}
