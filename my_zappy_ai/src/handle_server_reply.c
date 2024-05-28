/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_server_reply
*/

#include "zappy_ai.h"

static bool get_map_size(client_t *client, char *reply)
{
    int nb_word = count_nb_word(reply, " \t\n");
    int *size_word = count_size_word(reply, " \t\n", nb_word);
    char **word = my_str_to_word(reply, " \t\n", nb_word, size_word);

    if (nb_word < 2
    || !my_str_only_cont(word[0], "0123456789")
    || !my_str_only_cont(word[1], "0123456789")) {
        return false;
    }
    client->world.size_x = atoi(word[0]);
    client->world.size_y = atoi(word[1]);
    if (client->world.size_x <= 0 || client->world.size_y <= 0) {
        return false;
    }
    return true;
}

static void handle_login(client_t *client, char *reply)
{
    char team_name[MAX_TEAMNAME_SIZE + 2] = {0};

    if (client->log_state == WAITING_WELCOME
    && strcmp(reply, NEW_CLIENT_MESSAGE) == 0) {
        snprintf(team_name, sizeof(team_name), "%s\n", client->player.team_name);
        send_cmd_to_server(client, team_name);
        client->log_state = WAITING_ID;
    } else if (client->log_state == WAITING_ID
    && my_str_only_cont(reply, "0123456789\n")) {
        client->player.id = atoi(reply);
        client->log_state = WAINTING_MAP_SIZE;
        handle_cmd_reply(client, NULL);
    } else if (client->log_state == WAINTING_MAP_SIZE
    && get_map_size(client, reply)) {
        client->log_state = LOGGED;
    } else {
        exit_client(0, "No enought space in the team.\n");
    }
}

void handle_server_reply(client_t *client, char *reply)
{
    printf("server reply: %s", reply);
    if (client->log_state < LOGGED) {
        handle_login(client, reply);
    } else {
        handle_cmd_reply(client, reply);
    }
}
