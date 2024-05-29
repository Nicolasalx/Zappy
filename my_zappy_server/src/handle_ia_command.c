/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_ia_command
*/

#include "zappy_server.h"

static void get_all_elevation_mate(server_t *server, client_t *client)
{
    client_t **mate = NULL;
    int nb_mate = 0;

    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (nb_mate >= elevation_req[client->player.level - 1].nb_players)
            return;
        if (server->clients[i].fd != 0 && server->clients[i].player.id
        != client->player.id && server->clients[i].player.pos_x ==
        client->player.pos_x && server->clients[i].player.pos_y ==
        client->player.pos_y && server->clients[i].player.level ==
        client->player.level && !server->clients[i].incentation_mate
        && !server->clients[i].in_incentation) {
            mate = my_calloc(sizeof(client_t *));
            *mate = &server->clients[i];
            (*mate)->in_incentation = true;
            append_node(&client->incentation_mate, create_node(mate));
            send_msg_client(server->clients[i].fd, "Elevation underway\n");
            ++nb_mate;
        }
    }
}


static bool handle_elevation_cmd(server_t *server,
    client_t *client, const ai_handler_t *command)
{
    bool elev_req = false;

    if (command->method != incatation_cmd) {
        return true;
    }
    elev_req = check_elevation_req(client, server,
        client->player.level, false);
    if (elev_req) {
        send_msg_client(client->fd, "Elevation underway\n");
        get_all_elevation_mate(server, client);
    } else {
        send_msg_client(client->fd, "ko\n");
    }
    pic_reply(server, client);
    return elev_req;
}

static void push_new_command(server_t *server, client_t *client,
    const ai_handler_t *command, char *arg)
{
    waiting_cmd_t *new_cmd = my_calloc(sizeof(waiting_cmd_t));

    if (my_listlen(client->waiting_cmd) >= 10) {
        printf(MAGENTA("[WARNING] command ignored\n"));
        return;
    }
    if (!handle_elevation_cmd(server, client, command)) {
        return;
    }
    if (arg) {
        new_cmd->args = my_strdup(arg);
    }
    new_cmd->method = command->method;
    new_cmd->time_to_wait = command->waiting_time;
    append_node(&client->waiting_cmd, create_node(new_cmd));
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
                return;
            } else {
                send_msg_client(client->fd, "ko: method not implemented\n");
            }
        }
    }
    send_msg_client(client->fd, "ko\n");
}
