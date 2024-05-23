/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** left_cmd
*/

#include "zappy_server.h"

void left_cmd(char *argv, client_t *client, server_t *server)
{
    switch (client->player.orientation) {
        case NORTH:
            client->player.orientation = WEST;
            break;
        case SOUTH:
            client->player.orientation = EAST;
            break;
        case EAST:
            client->player.orientation = NORTH;
            break;
        case WEST:
            client->player.orientation = SOUTH;
            break;
    }
    send_msg_client(client->fd, "ok\n");
    ppo_reply(server, client);
}
