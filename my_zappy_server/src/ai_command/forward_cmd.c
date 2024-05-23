/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** forward_cmd
*/

#include "zappy_server.h"

void forward_cmd(char *argv, client_t *client, server_t *server)
{
    switch (client->player.orientation) {
        case NORTH:
            if (client->player.pos_y - 1 < 0) {
                client->player.pos_y = server->world.size_y;
            } else {
                client->player.pos_y -= 1;
            }
            break;
        case SOUTH:
            if (client->player.pos_y + 1 >= server->world.size_y) {
                client->player.pos_y = 0;
            } else {
                client->player.pos_y += 1;
            }
            break;
        case EAST:
            if (client->player.pos_x + 1 >= server->world.size_x) {
                client->player.pos_x = 0;
            } else {
                client->player.pos_x += 1;
            }
            break;
        case WEST:
            if (client->player.pos_x - 1 < 0) {
                client->player.pos_x = server->world.size_x;
            } else {
                client->player.pos_x -= 1;
            }
            break;

    }
    send_msg_client(client->fd, "ok\n");
}
