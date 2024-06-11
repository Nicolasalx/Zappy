/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** take_object_cmd
*/

#include "zappy_server.h"

void take_object_cmd(char *argv, client_t *client, server_t *server)
{
    char *object = strtok(argv, "\n");

    for (int i = 0; i < NB_ITEM; i++) {
        if (strcmp(object, object_list[i]) == 0
        && server->game.world.map[client->player.pos_y]
        [client->player.pos_x].item[i] > 0) {
            server->game.world.map[client->player.pos_y]
            [client->player.pos_x].item[i] -= 1;
            client->player.inventory[i] += 1;
            send_msg_client(client->fd, "ok\n");
            pgt_reply(server, client, i);
            pin_reply(server, client);
            bct_reply(server, client->player.pos_x, client->player.pos_y);
            if (server->opt.is_debug == true) {
                printf("[Debug] Object %s taken by %d on tile X:%d Y:%d\n",
                object_list[i], client->player.id, client->player.pos_x, client->player.pos_y);
            }
            return;
        }
    }
    send_msg_client(client->fd, "ko\n");
}
