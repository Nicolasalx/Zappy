/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** special_reply_handler
*/

#include "zappy_ai.h"

const special_reply_t special_reply[] = {
    {"End of Game\n", -1, end_of_game_cmd_reply},
    {"eject: ", 7, eject_cmd_reply},
    {"message ", 8, message_cmd_reply},
    {"dead\n", -1, dead_cmd_reply},
    {"Elevation underway\n", -1, elevation_cmd_reply},
    {NULL, 0, NULL}
};

void end_of_game_cmd_reply(client_t *client, char *)
{
    sem_post(&get_thread_list(NULL)->end_game);
    exit_client(client, 0, NULL);
}

void eject_cmd_reply(client_t *, char *)
{
}

void message_cmd_reply(client_t *client, char *reply)
{
    broadcast_reply(client, reply);
}

void dead_cmd_reply(client_t *client, char *)
{
    exit_client(client, 0, NULL);
}

void elevation_cmd_reply(client_t *client, char *)
{
    client->last_cmd = INCANTATION;
}
