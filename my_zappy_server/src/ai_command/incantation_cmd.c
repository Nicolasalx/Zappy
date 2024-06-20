/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation_cmd
*/

#include "zappy_server.h"

bool is_part_of_elevation(client_t *client, client_t *mate)
{
    node_t *current = client->player.incentation_mate;

    if (client->player.incentation_mate == NULL) {
        return false;
    }
    do {
        if ((*GET_DATA(current, client_t *))->player.id
            == mate->player.id) {
            return true;
        }
        current = current->next;
    } while (current != client->player.incentation_mate);
    return false;
}

static void cancel_elevation(client_t *client)
{
    node_t *current = client->player.incentation_mate;

    if (client->player.incentation_mate == NULL) {
        return;
    }
    do {
        (*GET_DATA(current, client_t *))->player.in_incentation = false;
        send_msg_client((*GET_DATA(current, client_t *))->fd, "ko\n");
        current = current->next;
    } while (current != client->player.incentation_mate);
    free_linked_list(&client->player.incentation_mate);
}

static void elevation_success(node_t *current,
    server_t *server, char *buffer)
{
    send_msg_client((*GET_DATA(current, client_t *))->fd, buffer);
    plv_reply(server, (*GET_DATA(current, client_t *)));
    if (server->opt.is_debug == true)
        printf("[Debug] Player %d level up to level %d\n",
            (*GET_DATA(current, client_t *))->player.id,
                (*GET_DATA(current, client_t *))->player.level);
}

static void end_elevation_debug(server_t *server, client_t *client)
{
    if (server->opt.is_debug == true) {
        printf("[Debug] Player %d level up to level %d\n",
            client->player.id, client->player.level);
    }
}

static void end_elevation(server_t *server, client_t *client)
{
    node_t *current = client->player.incentation_mate;
    char buffer[100] = {0};

    client->player.level += 1;
    snprintf(buffer, sizeof(buffer), "Current level: %d\n",
        client->player.level);
    send_msg_client(client->fd, buffer);
    plv_reply(server, client);
    if (client->player.incentation_mate == NULL) {
        end_elevation_debug(server, client);
        return;
    }
    do {
        (*GET_DATA(current, client_t *))->player.in_incentation = false;
        (*GET_DATA(current, client_t *))->player.level += 1;
        elevation_success(current, server, buffer);
        current = current->next;
    } while (current != client->player.incentation_mate);
    free_linked_list(&client->player.incentation_mate);
}

static void level_up_player(server_t *server,
    int i, int j, int *nb_player_lvl_8)
{
    if (server->clients[j].fd != 0
    && server->clients[j].player.team == &server->game.team_list[i]
    && server->clients[j].player.level == 8) {
        *nb_player_lvl_8 += 1;
    }
}

team_t *condition_win(server_t *server)
{
    int nb_player_lvl_8 = 0;

    for (int i = 0; i < server->game.team_count; ++i) {
        for (int j = 0; j < MAX_CLIENT; ++j) {
            level_up_player(server, i, j, &nb_player_lvl_8);
        }
        if (nb_player_lvl_8 >= 6) {
            return &server->game.team_list[i];
        }
        nb_player_lvl_8 = 0;
    }
    return NULL;
}

static void incantation_debug(server_t *server, client_t *client)
{
    if (server->opt.is_debug == true) {
        printf("[Debug] Incantation of player %d finished\n",
            client->player.id);
    }
}

void incatation_cmd(char *, client_t *client, server_t *server)
{
    team_t *winning_team = NULL;

    if (server->opt.is_debug == true)
        printf("[Debug] Starting post incantation verification\n");
    if (!check_elevation_req(client, server, client->player.level, true)) {
        cancel_elevation(client);
        send_msg_client(client->fd, "ko\n");
        pie_reply(server, client, false);
        return;
    }
    remove_elevation_req(client, server, client->player.level);
    end_elevation(server, client);
    incantation_debug(server, client);
    pie_reply(server, client, true);
    winning_team = condition_win(server);
    if (winning_team) {
        printf("[Debug] Team %s won the game\n", winning_team->name);
        seg_reply(server, winning_team);
    }
}
