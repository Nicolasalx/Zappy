/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_cmd_reply
*/

#include "zappy_ai.h"

void handle_cmd_reply(client_t *client, char *reply)
{
    if (reply && strncmp("eject: ", reply, 7) == 0) {

    } else if (reply && strncmp("message ", reply, 8) == 0) {
        broadcast_reply(client, reply);
    } else if (reply && strcmp("dead\n", reply) == 0) {
        printf("dead: %d\n", client->strategy);
    } else if (reply && strcmp(reply, "Elevation underway\n") == 0) {
        return;
    } {
        for (int i = 0; i < NB_ACTION; ++i) {
            if ((int) client->last_cmd == i) {
                if (reply_handler[i].method) {
                    reply_handler[i].method(client, reply);
                } else {
                    //printf("Method not implemented.\n");
                }
            }
        }
        pop_cmd_to_make(client);
    }
}
