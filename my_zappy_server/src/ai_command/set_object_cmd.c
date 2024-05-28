/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** set_object_cmd
*/

#include "zappy_server.h"

void set_object_cmd(char *argv, client_t *client, server_t *server)
{
    char *object = strtok(argv, "\n");

    for (int i = 0; i < NB_ITEM; i++) {
        if (strcmp(object, object_list[i]) == 0) {
            if (client->player.inventory[i] > 0) {
                client->player.inventory[i] -= 1;
                server->world.map[client->player.pos_y]
                [client->player.pos_x].item[i] += 1;
                send_msg_client(client->fd, "ok\n");
                pin_reply(server, client);
                pdr_reply(server, client, i);
                return;
            }
        }
    }
    send_msg_client(client->fd, "ko\n");
}
