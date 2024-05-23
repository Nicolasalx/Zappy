/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pin_cmd
*/

#include "zappy_server.h"

void pin_cmd(int, char **argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    int id = 0;

    if (!my_str_only_cont(argv[0], "0123456789")) {
        send_msg_client(client->fd, "sbp\n");
        return;
    }
    id = atoi(argv[0]);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic == false && server->clients[i].player.id == id) {
            snprintf(buffer, sizeof(buffer), "pin %d %d %d %d %d %d %d %d %d %d\n", id,
                server->clients[i].player.pos_x,
                server->clients[i].player.pos_y,
                server->clients[i].player.inventory[FOOD],
                server->clients[i].player.inventory[LINEMATE],
                server->clients[i].player.inventory[DERAUMERE],
                server->clients[i].player.inventory[SIBUR],
                server->clients[i].player.inventory[MENDIANE],
                server->clients[i].player.inventory[PHIRAS],
                server->clients[i].player.inventory[THYSTAME]);
            send_msg_client(client->fd, buffer);
            return;
        }
    }
    send_msg_client(client->fd, "sbp\n");
}