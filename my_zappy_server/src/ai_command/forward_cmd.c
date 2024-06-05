/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** forward_cmd
*/

#include "zappy_server.h"

void forward_cmd(char *, client_t *client, server_t *server)
{
    switch (client->player.orientation) {
        case NORTH:
            client->player.pos_y = (client->player.pos_y - 1
                + server->game.world.size_y) % server->game.world.size_y;
            break;
        case SOUTH:
            client->player.pos_y = (client->player.pos_y
                + 1) % server->game.world.size_y;
            break;
        case WEST:
            client->player.pos_x = (client->player.pos_x
                - 1 + server->game.world.size_x) % server->game.world.size_x;
            break;
        case EAST:
            client->player.pos_x = (client->player.pos_x
                + 1) % server->game.world.size_x;
            break;
    }
    send_msg_client(client->fd, "ok\n");
    ppo_reply(server, client);
}
