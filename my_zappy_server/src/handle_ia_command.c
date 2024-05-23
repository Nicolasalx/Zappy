/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_ia_command
*/

#include "zappy_server.h"

static void push_new_command(server_t *server, client_t *client,
    ai_handler_t *command, char *arg)
{
    if (my_listlen(client->waiting_cmd) >= 10) {
        return;
    }

}

void handle_ai_input(server_t *server, client_t *client, char *cmd)
{
    char *first_part = strpbrk(cmd, " \t");
    char *arg = first_part;

    if (first_part) {
        for (; *arg != '\0' && (*arg == ' ' || *arg == '\t'); ++arg);
        *first_part = '\0';
        first_part = cmd;
    } else {
        first_part = cmd;
        arg = NULL;
    }
    for (int i = 0; ai_cmd_handler[i].name != NULL; ++i) {
        if (strcmp(first_part, ai_cmd_handler[i].name) == 0
        && ai_cmd_handler[i].has_arg == (arg != NULL)) {
            if (ai_cmd_handler[i].method) {
                push_new_command(server, client, &ai_cmd_handler[i], arg);
                // ai_cmd_handler[i].method(arg, client, server);
                return;
            } else {
                send_msg_client(client->fd, "ko: method not implemented\n");
            }
        }
    }
    send_msg_client(client->fd, "ko\n");
}
