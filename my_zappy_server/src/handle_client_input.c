/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_client_input
*/

#include "zappy_server.h"

void handle_client_input(server_t *server, client_t *client, char *cmd)
{
    (void) server;
    printf("client send: %s\n", cmd);
    // check client type (is GRAPHICAL)
    int nb_word = count_nb_word(cmd, " \t\n");
    int *size_word = count_size_word(cmd, " \t\n", nb_word);
    char **word = my_str_to_word(cmd, " \t\n", nb_word, size_word);

    for (size_t i = 0; gui_cmd_handler[i].name != NULL; ++i) {
        if (nb_word > 0 && strcmp(word[0], gui_cmd_handler[i].name) == 0) {
            if (nb_word - 1 == gui_cmd_handler[i].nb_arg) {
                if (gui_cmd_handler[i].method) {
                    gui_cmd_handler[i].method(nb_word - 1, &word[1], client, server);
                } else {
                    send_msg_client(client->fd, "method not implemented\n");
                }
            } else {
                send_msg_client(client->fd, "sbp\n");
            }
            return;
        }
    }
    send_msg_client(client->fd, "suc\n");
}
