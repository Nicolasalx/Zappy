/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tpegg_cmd
*/

#include "zappy_server.h"

static bool kill_egg(server_t *server, int i, char **argv)
{
    node_t *current = NULL;
    int id = atoi(argv[0]);

    current = server->game.team_list[i].egg_list;
    if (server->game.team_list[i].egg_list == NULL) {
        return false;
    }
    do {
        if (GET_DATA(current, egg_t)->nb == id) {
            printf("Egg %d has been killed\n", id);
            edi_reply(server, &server->clients[i], GET_DATA(current, egg_t));
            delete_node(&server->game.team_list[i].egg_list, current);
            return true;
        }
        if (server->game.team_list[i].egg_list == NULL) {
            return true;
        }
        current = current->next;
    } while (current != server->game.team_list[i].egg_list);
    return false;
}

void killegg_cmd(int, char **argv, server_t *server)
{
    if (!my_str_only_cont(argv[0], "0123456789")) {
        printf("Error: invalid argument\n");
        return;
    }
    for (int i = 0; i < server->game.team_count; i++) {
        if (kill_egg(server, i, argv)) {
            return;
        }
    }
    printf("Error: egg id not found\n");
}
