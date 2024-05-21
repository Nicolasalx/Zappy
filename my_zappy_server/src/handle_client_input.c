/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_client_input
*/

#include "zappy_server.h"

static void handle_gui_input(server_t *server, client_t *client, char *cmd)
{
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

static void handle_ai_input(server_t *server, client_t *client, char *cmd)
{
    send_msg_client(client->fd, "method not implemented\n");
}

void handle_client_input(server_t *server, client_t *client, char *cmd)
{
    char buffer[100] = {0};
    char buffer2[100] = {};
    char buffer3[10000] = {};

    printf("client send: %s\n", cmd);

    if (client->is_graphic) {
        handle_gui_input(server, client, cmd);
    } else if (client->player.team) {
        handle_ai_input(server, client, cmd);
    } else {
        if (strcmp(cmd, "GRAPHIC\n") == 0) {
            client->is_graphic = true;
            // send info to client
            // trust the process
            sprintf(buffer3, "msz %d %d\nsgt %d", server->world.size_x, server->world.size_y, server->freq);
            send_msg_client(client->fd, buffer3);
        } else {
            for (int i = 0; i < server->team_count; ++i) {
                if (strlen(cmd) > 1 && strncmp(cmd, server->team_list[i].name, strlen(cmd) - 1) == 0) {
                    client->player.team = &server->team_list[i];
                    init_player(client);
                    server->team_list[i].remaining_place -= 1;
                    sprintf(buffer, "%d\n", server->team_list[i].remaining_place);
                    send_msg_client(client->fd, buffer);
                    sprintf(buffer2, "%d %d\n", server->world.size_x, server->world.size_y);
                    send_msg_client(client->fd, buffer2);
                    return;
                }
            }
            send_msg_client(client->fd, "ko (not logged in)\n");
        }
    }
}
