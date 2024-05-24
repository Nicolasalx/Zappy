/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pic_reply
*/

#include "zappy_server.h"

static void get_mate(char *buff, client_t *client, server_t *server)
{
    char num_player[15] = {0};

    snprintf(num_player, sizeof(num_player), " %d", client->player.id);
    strcat(buff, num_player);
    memset(num_player, 0, sizeof(num_player));
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 && server->clients[i].player.id != client->player.id
            && server->clients[i].player.team == client->player.team
            && server->clients[i].in_incentation) {
            snprintf(num_player, sizeof(num_player), " %d", server->clients[i].player.id);
            strcat(buff, num_player);
            memset(num_player, 0, sizeof(num_player));
        }
    }
    strcat(buff, "\n");
}

void pic_reply(server_t *server, client_t *client)
{
    char buffer[1024] = {0};

    snprintf(buffer, sizeof(buffer), "pic %d %d %d",
        client->player.pos_x, client->player.pos_y, client->player.level);
    get_mate(buffer, client, server);
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic == true) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
