/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look_cmd
*/

#include "zappy_server.h"

// XOOOOOOOOO 7
// 789OOOOO56 8
// 34OOOOOOO2 9

// 0123456789

static void get_item_str(char *buff, int *item)
{
    bool first = true;

    for (int i = 0; i < NB_ITEM; ++i) {
        for (int j = 0; j < item[i]; ++j) {
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
            get_item_str(buff, server->world.map
                [(client->player.pos_y - i + server->world.size_y) % server->world.size_y]
                [(x + server->world.size_x) % server->world.size_x].item);
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
            get_item_str(buff, server->world.map
                [(client->player.pos_y + i) % server->world.size_y]
                [(x + server->world.size_x) % server->world.size_x].item);
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
            get_item_str(buff, server->world.map
                [(y + server->world.size_y) % server->world.size_y]
                [(client->player.pos_x + i) % server->world.size_x].item);
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
            get_item_str(buff, server->world.map
                [(y + server->world.size_y) % server->world.size_y]
                [(client->player.pos_x - i + server->world.size_x) % server->world.size_x].item);
            if (y < (client->player.pos_y + i) || i < client->player.level) {
                strcat(buff, ",");
            }
        }
    }
    strcat(buff, "]\n");
    send_msg_client(client->fd, buff);
}

void look_cmd(char *argv, client_t *client, server_t *server)
{
    --client->player.level;
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
    ++client->player.level;
}
