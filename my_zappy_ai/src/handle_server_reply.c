/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_server_reply
*/

#include "zappy_ai.h"

static bool get_map_size(client_t *client, char *reply)
{
    int nb_word = 0;
    int *size_word = NULL;
    char **word = NULL;

    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    nb_word = count_nb_word(reply, " \t\n");
    size_word = count_size_word(reply, " \t\n", nb_word);
    word = my_str_to_word(reply, " \t\n", nb_word, size_word);
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
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

static void handle_login_state(client_t *client, char *reply)
{
    if (client->log_state == WAITING_MAP_SIZE && get_map_size(client, reply)) {
        client->log_state = LOGGED;
        return;
    }
    exit_client(client, 0, "Not enought space in the team.\n");
}

static void handle_login(client_t *client, char *reply)
{
    char team_name[MAX_TEAMNAME_SIZE + 2] = {0};

    if (client->log_state == WAITING_WELCOME
        && strcmp(reply, NEW_CLIENT_MESSAGE) == 0) {
        snprintf(team_name, sizeof(team_name),
            "%s\n", client->player.team_name);
        send_cmd_to_server(client, team_name);
        client->log_state = WAITING_ID;
        return;
    }
    if (client->log_state == WAITING_ID
        && my_str_only_cont(reply, "0123456789\n")) {
        client->player.id = atoi(reply);
        client->log_state = WAITING_MAP_SIZE;
        handle_cmd_reply(client, NULL);
        return;
    }
    handle_login_state(client, reply);
}

void handle_server_reply(client_t *client, char *reply)
{
    if (client->log_state < LOGGED) {
        handle_login(client, reply);
    } else {
        handle_cmd_reply(client, reply);
    }
}
