/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_cmd
*/

#include "zappy_server.h"

int calculate_direction(client_t *src, client_t *dest)
{
    int dx = dest->player.pos_x - src->player.pos_x;
    int dy = dest->player.pos_y - src->player.pos_y;
    int direction = 0;

    if (abs(dx) > abs(dy))
        direction = (dx > 0) ? 3 : 7;
    else
        direction = (dy > 0) ? 1 : 5;
    if (dx > 0 && dy > 0)
        direction = 2;
    if (dx > 0 && dy < 0)
        direction = 4;
    if (dx < 0 && dy < 0)
        direction = 6;
    if (dx < 0 && dy > 0)
        direction = 8;
    direction = ((direction - (dest->player.orientation * 2)) % 8);
    if (direction == 0)
        direction = 8;
    return direction;
}

void broadcast_cmd(char *argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    char *message = strtok(argv, "\n");
    int direction = 0;

    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic != true
        && server->clients[i].player.team
        && client->player.id != server->clients[i].player.id) {
            direction = calculate_direction(client, &server->clients[i]);
            snprintf(buffer, sizeof(buffer), "message %d, %s\n",
                direction, message);
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
    send_msg_client(client->fd, "ok\n");
    pbc_reply(server, client, message);
}
