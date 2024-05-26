/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** get_client_input
*/

#include "zappy_server.h"

void get_client_input(server_t *server, client_t *client)
{
    char cmd_data[BUFFER_SIZE] = {0};
    ssize_t nb_byte = read(client->fd, &cmd_data, sizeof(cmd_data));

    if (nb_byte == -1)
        return;
    if (nb_byte == 0) {
        printf(YELLOW("A client has left")"\n");
        if (client->player.id != -1)
            pdi_reply(server, client);
        remove_client(client);
        return;
    }
    if (nb_byte >= BUFFER_SIZE) {
        dprintf(2, RED("Client input is incompatible with the server.")"\n");
        if (client->player.id != -1)
            pdi_reply(server, client);
        remove_client(client);
        return;
    }
    handle_client_input(server, client, cmd_data);
}
