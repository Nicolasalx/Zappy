/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** sst_cmd
*/

#include "zappy_server.h"

void sst_cmd(int, char **argv, client_t *client, server_t *server)
{
    char buffer[100] = {0};

    if (!my_str_only_cont(argv[0], "0123456789")) {
        send_msg_client(client->fd, "sbp\n");
        return;
    }
    server->opt.freq = atoi(argv[0]);
    snprintf(buffer, sizeof(buffer), "sst %d\n", (int)server->opt.freq);
    send_msg_client(client->fd, buffer);
}
