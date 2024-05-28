/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** queen_management
*/

#include "zappy_ai.h"


void broad_cast_cmd(client_t *client)
{
    send_command_broad_cast(client, "Queen role taken");
}

bool ok = false;

void queen_management(client_t *client)
{
    if (!ok) {
        broad_cast_cmd(client);
        ok = true;
    }
}
