/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** give_cmd
*/

#include "zappy_server.h"

static bool add_to_inventory(server_t *server, int i, int nb, char **argv)
{
    for (int j = 0; j < NB_ITEM; j++) {
        if (strcmp(argv[1], object_list[j]) == 0) {
            server->clients[i].player.inventory[j] += nb;
            printf("You have given %s x%d to "
                "player %d\n", object_list[j], nb, i);
            pin_reply(server, &server->clients[i]);
            return true;
        }
    }
    return false;
}

static bool check_client(server_t *server, char **argv, int i)
{
    int id = atoi(argv[0]);
    int nb = atoi(argv[2]);

    if (server->clients[i].fd != 0 && server->clients[i].player.id == id
    && server->clients[i].player.is_graphic == false
    && server->clients[i].player.team) {
        if (add_to_inventory(server, i, nb, argv)) {
            return true;
        }
    }
    return false;
}

void give_cmd(int, char **argv, server_t *server)
{
    int nb = atoi(argv[2]);

    if (!my_str_only_cont(argv[0], "0123456789")
    || !my_str_only_cont(argv[2], "0123456789")
    || nb <= 0 || nb > 100) {
        printf("Error: invalid argument\n");
        return;
    }
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (check_client(server, argv, i)) {
            return;
        }
    }
    printf("Error: invalid argument\n");
}
