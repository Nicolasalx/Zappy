/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** take_cmd
*/

#include "zappy_ai.h"

void take_command(client_t *client, char *ressource)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "Take %s\n", ressource);
    for (int i = 0; i < NB_ITEM; ++i)
        if (strcmp(ressource, object_list[i]) == 0) {
            client->player.last_item_taken = i;
            break;
        }
    push_new_command(client, TAKE, buffer);
}
