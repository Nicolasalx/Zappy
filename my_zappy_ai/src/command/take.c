/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** take
*/

#include "zappy_ai.h"

void take_command(client_t *client, char *ressource)
{
    char buffer[100] = {0};

    printf("Take\n");
    client->last_cmd = TAKE;
    snprintf(buffer, sizeof(buffer), "Take %s\n", ressource);
    for (int i = 0; i < NB_ITEM; ++i)
        if (strcmp(ressource, object_list[i]) == 0) {
            client->player.inventory[i] += 1;
            client->shared_inventory[i] += 1;
            break;
        }
    push_new_command(client, TAKE, buffer);
}