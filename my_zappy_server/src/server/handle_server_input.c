/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_server_input
*/

#include "zappy_server.h"

static void handle_new_server_cmd(char *cmd, server_t *server)
{
    int nb_word = count_nb_word(cmd, " \t\n");
    int *size_word = count_size_word(cmd, " \t\n", nb_word);
    char **word = my_str_to_word(cmd, " \t\n", nb_word, size_word);

    for (size_t i = 0; server_cmd_handler[i].name != NULL; ++i) {
        if (nb_word > 0 && strcmp(word[0], server_cmd_handler[i].name) == 0) {
            if (nb_word - 1 == server_cmd_handler[i].nb_arg) {
                if (server_cmd_handler[i].method) {
                    server_cmd_handler[i].method(nb_word - 1, &word[1], server);
                } else {
                    printf("method not implemented\n");
                }
            } else {
                printf("%s\n", server_cmd_handler[i].usage);
            }
            return;
        }
    }
    printf("Unknown command.\n");
}

void handle_server_input(server_t *server)
{
    char cmd_data[BUFFER_SIZE] = {0};
    ssize_t nb_byte = 0;

    if (FD_ISSET(STDIN_FILENO, &server->read_set)) {
        nb_byte = read(STDIN_FILENO, &cmd_data, sizeof(cmd_data) - 1);
        if (nb_byte == -1 || nb_byte == 0)
            return;
        if (nb_byte >= BUFFER_SIZE) {
            dprintf(2, RED("Server input is incompatible is too long.")"\n");
            return;
        }
        handle_new_server_cmd(cmd_data, server);
    }
}
