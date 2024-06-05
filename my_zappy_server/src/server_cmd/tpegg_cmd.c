/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tpegg_cmd
*/

#include "zappy_server.h"

static bool tp_error_management(char **argv, server_t *server)
{
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    if (!my_str_only_cont(argv[0], "0123456789")
    || !my_str_only_cont(argv[1], "0123456789")
    || !my_str_only_cont(argv[2], "0123456789")
    || x < 0 || x >= server->game.world.size_x
    || y < 0 || y >= server->game.world.size_y) {
        printf("Error: invalid argument\n");
        return true;
    }
    return false;
}

static bool tp_egg(server_t *server, int i, char **argv)
{
    node_t *current = NULL;
    int id = atoi(argv[0]);
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    current = server->game.team_list[i].egg_list;
    if (server->game.team_list[i].egg_list == NULL) {
        return false;
    }
    do {
        if (GET_DATA(current, egg_t)->nb == id) {
            GET_DATA(current, egg_t)->pos_x = x;
            GET_DATA(current, egg_t)->pos_y = y;
            printf("Egg %d has been teleported to %d %d\n", id, x, y);
            edi_reply(server, &server->clients[i], GET_DATA(current, egg_t));
            enw_reply(server, &server->clients[i], GET_DATA(current, egg_t));
            return true;
        }
        current = current->next;
    } while (current != server->game.team_list[i].egg_list);
    return false;
}

void tpegg_cmd(int, char **argv, server_t *server)
{
    if (tp_error_management(argv, server)) {
        return;
    }
    for (int i = 0; i < server->game.team_count; i++) {
        if (tp_egg(server, i, argv)) {
            return;
        }
    }
    printf("Error: egg id not found\n");
}
