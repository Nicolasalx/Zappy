/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** plv_cmd
*/

#include "zappy_server.h"

void plv_cmd(int, char **argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    int id = 0;

    if (!my_str_only_cont(argv[0], "0123456789")) {
        send_msg_client(client->fd, "sbp\n");
        return;
    }
    id = atoi(argv[0]);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0
        && server->clients[i].is_graphic == false
        && server->clients[i].player.id == id) {
            snprintf(buffer, sizeof(buffer), "plv %d %d\n",
            id, server->clients[i].player.level);
            send_msg_client(client->fd, buffer);
            return;
        }
    }
    send_msg_client(client->fd, "sbp\n");
}
