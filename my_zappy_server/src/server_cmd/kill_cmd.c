/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** kill_cmd
*/

#include "zappy_server.h"

void kill_cmd(int, char **argv, server_t *server)
{
    int id = atoi(argv[0]);

    if (!my_str_only_cont(argv[0], "0123456789")) {
        printf("Error: invalid argument\n");
        return;
    }
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].player.id == id
        && server->clients[i].is_graphic == false) {
            send_msg_client(server->clients[i].fd, "dead\n");
            pdi_reply(server, &server->clients[i]);
            remove_client(&server->clients[i]);
            return;
        }
    }
    printf("Error: client not found\n");
}
