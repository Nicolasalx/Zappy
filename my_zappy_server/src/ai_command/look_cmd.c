/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look_cmd
*/

#include "zappy_server.h"

static void look_north(client_t *client, server_t *server)
{
    char buff[BUFFER_SIZE] = {0};

    strcpy(buff, "[");
    for (int i = 0; i <= client->player.level; ++i) {
        for (int x = (client->player.pos_x - i);
        x <= (client->player.pos_x + i); ++x) {
            get_item_str(buff, (x + server->world.size_x)
            % server->world.size_x,
                (client->player.pos_y - i + server->world.size_y)
                % server->world.size_y, server);
            append_with_coma_if_needed_x(client, buff, x, i);
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
        for (int x = (client->player.pos_x - i);
        x <= (client->player.pos_x + i); ++x) {
            get_item_str(buff,
                (x + server->world.size_x) % server->world.size_x,
                (client->player.pos_y + i)
                % server->world.size_y, server);
            append_with_coma_if_needed_x(client, buff, x, i);
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
        for (int y = (client->player.pos_y - i); y
        <= (client->player.pos_y + i); ++y) {
            get_item_str(buff,
                (client->player.pos_x + i) % server->world.size_x,
                (y + server->world.size_y) % server->world.size_y, server);
            append_with_coma_if_needed_y(client, buff, y, i);
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
        for (int y = (client->player.pos_y - i); y
        <= (client->player.pos_y + i); ++y) {
            get_item_str(buff, (client->player.pos_x - i
            + server->world.size_x) % server->world.size_x,
                (y + server->world.size_y) % server->world.size_y, server);
            append_with_coma_if_needed_y(client, buff, y, i);
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
