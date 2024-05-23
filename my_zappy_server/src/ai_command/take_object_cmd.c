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
        if (strcmp(object, object_list[i]) == 0) {
            if (server->world.map[client->player.pos_y][client->player.pos_x].item[i] > 0) {
                printf("%d\n", server->world.map[client->player.pos_y][client->player.pos_x].item[i]);
                printf("%d\n", client->player.pos_y);
                printf("%d\n", client->player.pos_x);
                server->world.map[client->player.pos_y][client->player.pos_x].item[i] -= 1;
                client->player.inventory[i] += 1;
                send_msg_client(client->fd, "ok\n");
                pgt_reply(server, client, i);
                return;
            }
        }
    }
    send_msg_client(client->fd, "ko\n");
}