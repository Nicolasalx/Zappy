/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_cmd_reply
*/

#include "zappy_ai.h"

static bool handle_special_reply(client_t *client, char *reply)
{
    if (!reply) {
        return false;
    }
    for (size_t i = 0; special_reply[i].name != NULL; ++i) {
        if ((special_reply[i].size == -1
        && strcmp(special_reply[i].name, reply) == 0)
        || (special_reply[i].size != -1 && strncmp(
        special_reply[i].name, reply, special_reply[i].size) == 0)) {
            special_reply[i].method(client, reply);
            return true;
        }
    }
    return false;
}

void handle_cmd_reply(client_t *client, char *reply)
{
    if (handle_special_reply(client, reply)) {
        return;
    }
    for (int i = 0; i < NB_ACTION; ++i) {
        if ((int) client->last_cmd == i
        && reply_handler[i].method) {
            reply_handler[i].method(client, reply);
        }
    }
    pop_cmd_to_make(client);
}
