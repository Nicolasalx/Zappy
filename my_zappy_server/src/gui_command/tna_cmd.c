/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tna_cmd
*/

#include "zappy_server.h"

void tna_cmd(int nb_args, char **argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};

    for (int i = 0; server->team_list[i].remaining_place != -1 && i < MAX_TEAM_NB; i++) {
        snprintf(buffer, sizeof(buffer), "tna %s\n", server->team_list[i].name);
        send_msg_client(client->fd, buffer);
    }
}
