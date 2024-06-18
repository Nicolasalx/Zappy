/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_cmd
*/

#include "zappy_server.h"

int compute_direction_helper(int dx, int dy, int direction)
{
    if (dx > 0 && dy > 0) {
        direction = 2;
    }
    if (dx > 0 && dy < 0) {
        direction = 4;
    }
    if (dx < 0 && dy < 0) {
        direction = 6;
    }
    if (dx < 0 && dy > 0) {
        direction = 8;
    }
    return direction;
}

int adjust_direction_for_orientation(int direction, int orientation)
{
    direction = (direction - orientation + 8) % 8;
    return direction;
}

int compute_direction(client_t *src, client_t *dest)
{
    int dx = dest->player.pos_x - src->player.pos_x;
    int dy = dest->player.pos_y - src->player.pos_y;
    int direction = 0;

    if (dx == 0 && dy == 0) {
        return 0;
    }
    if (abs(dx) > abs(dy)) {
        direction = (dx > 0) ? 3 : 7;
    } else {
        direction = (dy > 0) ? 1 : 5;
    }
    direction = compute_direction_helper(dx, dy, direction);
    direction =
        adjust_direction_for_orientation(direction, src->player.orientation);
    return direction;
}

static void broadcast_ok(server_t *server, client_t *client, char *message)
{
    send_msg_client(client->fd, "ok\n");
    pbc_reply(server, client, message);
}

static bool broadcast_fail(client_t *client, char *message)
{
    if (message == NULL || strlen(message) > (MAX_BROADCAST_LEN)) {
        send_msg_client(client->fd, "ko\n");
        return false;
    }
    return true;
}

void broadcast_cmd(char *argv, client_t *client, server_t *server)
{
    char buffer[BUFFER_SIZE + 1] = {0};
    char *message = strtok(argv, "\n");
    int direction = 0;

    if (!broadcast_fail(client, message))
        return;
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 && !server->clients[i].player.is_graphic
            && server->clients[i].player.team
            && client->player.id != server->clients[i].player.id) {
                direction = compute_direction(client, &server->clients[i]);
                direction = adjust_direction_for_orientation
                    (direction, server->clients[i].player.orientation);
                snprintf(buffer, BUFFER_SIZE, "message %d, %s\n",
                    direction, message);
                send_msg_client(server->clients[i].fd, buffer);
        }
    }
    broadcast_ok(server, client, message);
}
