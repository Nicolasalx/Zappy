/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** dead_reply
*/

#include "zappy_ai.h"

void dead_reply(client_t *client, char *)
{
    if (client->strategy == QUEEN) {
        for (int i = 0; i < 100; ++i) {
            printf("QUEEN DEAD\n");
        }
    }
    return;
}