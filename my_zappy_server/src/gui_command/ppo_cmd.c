/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** ppo_cmd
*/

#include "zappy_server.h"

static void send_ppo_reply(char *buffer, int id,
    client_t *client, server_t *server)
{
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0
        && server->clients[i].player.is_graphic == false
        && server->clients[i].player.id == id
        && server->clients[i].player.team) {
            snprintf(buffer, 100, "ppo %d %d %d %d\n", id,
                server->clients[i].player.pos_x,
                server->clients[i].player.pos_y,
                server->clients[i].player.orientation + 1);
            send_msg_client(client->fd, buffer);
            return;
        }
    }
}

void ppo_cmd(int, char **argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    int id = 0;

    if (!my_str_only_cont(argv[0], "0123456789")) {
        send_msg_client(client->fd, "sbp\n");
        return;
    }
    id = atoi(argv[0]);
    send_ppo_reply(buffer, id, client, server);
    send_msg_client(client->fd, "sbp\n");
}
