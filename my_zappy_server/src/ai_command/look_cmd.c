/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look_cmd
*/

#include "zappy_server.h"

static void get_item_str(char *buff, int x, int y, server_t *server)
{
    bool first = true;

    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0
            && server->clients[i].player.pos_x == x
            && server->clients[i].player.pos_y == y) {
            if (!first) {
                strcat(buff, " ");
            }
            strcat(buff, "player");
            first = false;
        }
    }
    for (int i = 0; i < NB_ITEM; ++i) {
        for (int j = 0; j < server->world.map[y][x].item[i]; ++j) {
            if (!first) {
                strcat(buff, " ");
            }
            strcat(buff, object_list[i]);
            first = false;
        }
    }
}

static void look_north(client_t *client, server_t *server)
{
    char buff[BUFFER_SIZE] = {0};

    strcpy(buff, "[");
    for (int i = 0; i <= client->player.level; ++i) {
        for (int x = (client->player.pos_x - i); x <= (client->player.pos_x + i); ++x) {
            get_item_str(buff, (x + server->world.size_x) % server->world.size_x,
                (client->player.pos_y - i + server->world.size_y) % server->world.size_y, server);
            if (x < (client->player.pos_x + i) || i < client->player.level) {
                strcat(buff, ",");
            }
        }
    }
    strcat(buff, "]\n");
    send_msg_client(client->fd, buff);
}

static void look_south(client_t *client, server_t *server)
{
    char buff[BUFFER_SIZE] = {0};

    strcpy(buff, "[");
    for (int i = 0; i <= client->player.level; ++i) {
        for (int x = (client->player.pos_x - i); x <= (client->player.pos_x + i); ++x) {
            get_item_str(buff,
                (x + server->world.size_x) % server->world.size_x,
                (client->player.pos_y + i) % server->world.size_y, server);
            if (x < (client->player.pos_x + i) || i < client->player.level) {
                strcat(buff, ",");
            }
        }
    }
    strcat(buff, "]\n");
    send_msg_client(client->fd, buff);
}

static void look_east(client_t *client, server_t *server)
{
    char buff[BUFFER_SIZE] = {0};

    strcpy(buff, "[");
    for (int i = 0; i <= client->player.level; ++i) {
        for (int y = (client->player.pos_y - i); y <= (client->player.pos_y + i); ++y) {
            get_item_str(buff,
                (client->player.pos_x + i) % server->world.size_x,
                (y + server->world.size_y) % server->world.size_y, server);
            if (y < (client->player.pos_y + i) || i < client->player.level) {
                strcat(buff, ",");
            }
        }
    }
    strcat(buff, "]\n");
    send_msg_client(client->fd, buff);
}

static void look_west(client_t *client, server_t *server)
{
    char buff[BUFFER_SIZE] = {0};

    strcpy(buff, "[");
    for (int i = 0; i <= client->player.level; ++i) {
        for (int y = (client->player.pos_y - i); y <= (client->player.pos_y + i); ++y) {
            get_item_str(buff, (client->player.pos_x - i + server->world.size_x) % server->world.size_x,
                (y + server->world.size_y) % server->world.size_y, server);
            if (y < (client->player.pos_y + i) || i < client->player.level) {
                strcat(buff, ",");
            }
        }
    }
    strcat(buff, "]\n");
    send_msg_client(client->fd, buff);
}

void look_cmd(char *, client_t *client, server_t *server)
{
    switch (client->player.orientation) {
        case NORTH:
            look_north(client, server);
            break;
        case SOUTH:
            look_south(client, server);
            break;
        case EAST:
            look_east(client, server);
            break;
        case WEST:
            look_west(client, server);
            break;
    }
}
