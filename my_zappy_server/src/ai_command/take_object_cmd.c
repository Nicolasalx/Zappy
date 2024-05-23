/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** take_object_cmd
*/

#include "zappy_server.h"

void take_object_cmd(char *argv, client_t *client, server_t *server)
{
    const char *object_names[] =
    {
            "FOOD",
            "LINEMATE",
            "DERAUMERE",
            "SIBUR",
            "MENDIANE",
            "PHIRAS",
            "THYSTAME"
    };
    for (int i = 0; i < NB_ITEM; i++) {
        if (strcmp(argv, object_names[i]) == 0) {
            if (server->world.map[client->player.pos_y][client->player.pos_x].item[i] > 0) {
                server->world.map[client->player.pos_y][client->player.pos_x].item[i]--;
                client->player.inventory[i]++;
                send_msg_client(client->fd, "ok\n");
                return;
            }
        }
    }
    send_msg_client(client->fd, "ko\n");
}