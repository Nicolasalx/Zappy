/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** set_object_cmd
*/

#include "zappy_server.h"

static void set_object_debug(server_t *server, client_t *client, int i)
{
    if (server->opt.is_debug == true) {
        printf("[Debug] Object %s set by %d on tile X:%d Y:%d\n",
            object_list[i], client->player.id, client->player.pos_x,
            client->player.pos_y);
    }
}

void set_object_cmd(char *argv, client_t *client, server_t *server)
{
    char *object = strtok(argv, "\n");

    for (int i = 0; i < NB_ITEM; i++) {
        if (strcmp(object, object_list[i]) == 0
        && client->player.inventory[i] > 0) {
            client->player.inventory[i] -= 1;
            server->game.world.map[client->player.pos_y]
            [client->player.pos_x].item[i] += 1;
            send_msg_client(client->fd, "ok\n");
            pdr_reply(server, client, i);
            pin_reply(server, client);
            bct_reply(server, client->player.pos_x, client->player.pos_y);
            set_object_debug(server, client, i);
            return;
        }
    }
    send_msg_client(client->fd, "ko\n");
}
