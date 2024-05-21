/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_player_data
*/

#include "zappy_server.h"

void handle_new_player(server_t *server, client_t *new_client)
{
    send_msg_client(new_client->fd, NEW_CLIENT_MESSAGE);
}
