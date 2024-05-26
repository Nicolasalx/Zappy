/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pic_reply
*/

#include "zappy_server.h"

static void get_mate(char *buff, client_t *client)
{
    char num_player[15] = {0};
    node_t *current = client->incentation_mate;

    snprintf(num_player, sizeof(num_player), " %d", client->player.id);
    strcat(buff, num_player);
    memset(num_player, 0, sizeof(num_player));
    if (client->incentation_mate == NULL) {
        strcat(buff, "\n");
        return;
    }
    do {
        snprintf(num_player, sizeof(num_player), " %d",
        (*GET_DATA(current, client_t *))->player.id);
        strcat(buff, num_player);
        memset(num_player, 0, sizeof(num_player));
        current = current->next;
    } while (current != client->incentation_mate);
    strcat(buff, "\n");
}

void pic_reply(server_t *server, client_t *client)
{
    char buffer[1024] = {0};

    snprintf(buffer, sizeof(buffer), "pic %d %d %d",
        client->player.pos_x, client->player.pos_y, client->player.level);
    get_mate(buffer, client);
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0
        && server->clients[i].is_graphic == true) {
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
