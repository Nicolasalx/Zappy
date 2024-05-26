/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** level_cmd
*/

#include "zappy_server.h"

void level_cmd(int, char **argv, server_t *server)
{
    int id = atoi(argv[0]);
    int level = atoi(argv[1]);

    if (!my_str_only_cont(argv[0], "0123456789")
    || !my_str_only_cont(argv[1], "0123456789")
    || level < 1 || level > 8) {
        printf("Error: invalid argument\n");
        return;
    }
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].player.id == id
        && server->clients[i].is_graphic == false) {
            server->clients[i].player.level = level;
            plv_reply(server, &server->clients[i]);
            return;
        }
    }
    printf("Error: client not found\n");
}
