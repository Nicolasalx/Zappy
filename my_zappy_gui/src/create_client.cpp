/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_client
*/

#include "zappy_gui.hpp"

void create_client(client_t *client)
{
    get_client(client);
    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd == -1) {
        exit_client(84, "Fail to create the client socket\n");
    }
    client->server_address.sin_family = AF_INET;
    client->server_address.sin_port = htons(client->port);
    if (connect(client->fd, (struct sockaddr *)
        &client->server_address, sizeof(client->server_address)) != 0) {
        exit_client(84, "Connection to the server failed.\n");
    }
    client->cmd_buffer = (char *) calloc(CMD_BUFFER_SIZE + 1, sizeof(char));
}
