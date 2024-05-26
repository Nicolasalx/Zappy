/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** give_cmd
*/

#include "zappy_server.h"

void give_cmd(int, char **argv, server_t *server)
{
    int id = atoi(argv[0]);
    int nb = atoi(argv[2]);
    bool is_player_id = false;

    if (!my_str_only_cont(argv[0], "0123456789")
    || !my_str_only_cont(argv[2], "0123456789")
    || nb < 0 || nb > 100) {
        printf("Error: invalid argument\n");
        return;
    }
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].player.id == id
        && server->clients[i].is_graphic == false) {
            is_player_id = true;
            for (int j = 0; j < NB_ITEM; j++) {
                if (strcmp(argv[1], object_list[j]) == 0) {
                    server->clients[i].player.inventory[j] += nb;
                    pin_reply(server, &server->clients[i]);
                    return;
                }
            }
        }
    }
    if (!is_player_id) {
        printf("Error: client not found\n");   
        return;
    }
    printf("Error: invalid object name\n");
}
