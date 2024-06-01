/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_gui_command
*/

#include "zappy_server.h"

static void call_gui_function(server_t *server,
    client_t *client, int *nb_word_i, char **word)
{
    if (nb_word_i[0] - 1 == gui_cmd_handler[nb_word_i[1]].nb_arg) {
        if (gui_cmd_handler[nb_word_i[1]].method) {
            gui_cmd_handler[nb_word_i[1]].method(
                nb_word_i[0] - 1, &word[1], client, server);
        } else {
            send_msg_client(client->fd, "method not implemented\n");
        }
    } else {
        send_msg_client(client->fd, "sbp\n");
    }
}

void handle_gui_input(server_t *server, client_t *client, char *cmd)
{
    int nb_word = count_nb_word(cmd, " \t\n");
    int *size_word = count_size_word(cmd, " \t\n", nb_word);
    char **word = my_str_to_word(cmd, " \t\n", nb_word, size_word);

    for (size_t i = 0; gui_cmd_handler[i].name != NULL; ++i) {
        if (nb_word > 0 && strcmp(word[0], gui_cmd_handler[i].name) == 0) {
            call_gui_function(server, client, (int[2]){nb_word, i}, word);
            return;
        }
    }
    send_msg_client(client->fd, "suc\n");
}
