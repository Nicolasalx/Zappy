/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** inventory_cmd
*/

#include "zappy_server.h"

void inventory_cmd(char *, client_t *client, server_t *)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "[food %d, linemate %d, deraumere %d, "
    "sibur %d, mendiane %d, phiras %d, thystame %d]\n",
    client->player.inventory[FOOD], client->player.inventory[LINEMATE],
    client->player.inventory[DERAUMERE], client->player.inventory[SIBUR],
    client->player.inventory[MENDIANE], client->player.inventory[PHIRAS],
    client->player.inventory[THYSTAME]);
    send_msg_client(client->fd, buffer);
}
