/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** ppo_cmd
*/

#include "zappy_server.h"

void ppo_cmd(int, char **argv, client_t *client, server_t *)
{
    char buffer[100] = {0};
    int id = atoi(argv[0]);

    // direction à r'ajouter
    snprintf(buffer, sizeof(buffer), "ppo #%d %d %d\n", id, 
        client[id].player.pos_x, client[id].player.pos_y);
    send_msg_client(client->fd, buffer);
}