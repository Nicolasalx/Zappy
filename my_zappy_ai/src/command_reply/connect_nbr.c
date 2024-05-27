/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** connect_nbr
*/

#include "zappy_ai.h"

void connect_nbr_command(client_t *client, char *reply)
{
    printf("Connect_nbr\n");
    client->remaining_spots = atoi(reply);
}
