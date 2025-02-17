/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** forward_cmd
*/

#include "zappy_server.h"

void forward_cmd_debug(server_t *server, client_t *client)
{
    send_msg_client(client->fd, "ok\n");
    ppo_reply(server, client);
    if (server->opt.is_debug == true)
        printf("[Debug] Player %d forward, new position: X:%d Y:%d O:%d\n",
        client->player.id, client->player.pos_x,
            client->player.pos_y, client->player.orientation);
}

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
    forward_cmd_debug(server, client);
}
