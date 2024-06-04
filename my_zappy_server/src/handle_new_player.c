/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_player_data
*/

#include "zappy_server.h"

void handle_new_player(server_t *, client_t *new_client)
{
    new_client->cmd_buffer = my_calloc(sizeof(char) * (BUFFER_SIZE + 1));
    send(new_client->fd, NEW_CLIENT_MESSAGE,
        sizeof(NEW_CLIENT_MESSAGE), MSG_NOSIGNAL);
}
