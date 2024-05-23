/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_ia_command
*/

#include "zappy_server.h"

void handle_ai_input(server_t *server, client_t *client, char *cmd)
{
    send_msg_client(client->fd, "sbp\n");
}
