/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** execute_client_input
*/

#include "zappy_server.h"

void execute_client_input(server_t *server,
    client_t *client, char *cmd_data)
{
    (void) server;
    (void) client;
    printf("client send: %s\n", cmd_data);
}
