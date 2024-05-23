/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** connect_nbr_cmd
*/

#include "zappy_server.h"

void connect_nbr_cmd(char *argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    int nb_team = 0;

    for (int i = 0; i < server->team_count; i++) {
        if (server->team_list[i].remaining_place >= server->client_nb) {
            nb_team += 1;
        }
    }
    snprintf(buffer, sizeof(buffer), "%d\n", nb_team);
    send_msg_client(client->fd, buffer);
}