/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pin_cmd
*/

#include "zappy_server.h"

void pin_cmd(int argc, char **argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    int id = 0;

    if (!my_str_only_cont(argv[0], "0123456789")) {
        send_msg_client(client->fd, "sbp\n");
        return;
    }
    id = atoi(argv[0]);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (client[i].fd != 0 && client[i].is_graphic == false && client[i].player.id == id) {
            snprintf(buffer, sizeof(buffer), "pin %d %d %d %d %d %d %d %d %d %d\n", id,
                server->clients[id].player.pos_x,
                server->clients[id].player.pos_y,
                server->clients[id].player.inventory[FOOD],
                server->clients[id].player.inventory[LINEMATE],
                server->clients[id].player.inventory[DERAUMERE],
                server->clients[id].player.inventory[SIBUR],
                server->clients[id].player.inventory[MENDIANE],
                server->clients[id].player.inventory[PHIRAS],
                server->clients[id].player.inventory[THYSTAME]);
            send_msg_client(client->fd, buffer);
            return;
        }
    }
    send_msg_client(client->fd, "sbp\n");
}