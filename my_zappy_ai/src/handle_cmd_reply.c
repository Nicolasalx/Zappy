/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_cmd_reply
*/

#include "zappy_ai.h"

void handle_cmd_reply(client_t *client, char *reply)
{
    if (!reply && client->last_cmd == NONE) {
        // first command
    }
    // handle other cmd
    // ! set last cmd var (ex: client->last_cmd = INVENTORY;)
}
