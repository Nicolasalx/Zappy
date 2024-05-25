/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation_cmd
*/

#include "zappy_server.h"

static void remove_elevation_req(client_t *client, server_t *server, int level)
{
    elevation_requirement_t req = elevation_requirement[level - 1];

    server->world.map[client->player.pos_y][client->player.pos_x].item[DERAUMERE] -= req.deraumere;
    server->world.map[client->player.pos_y][client->player.pos_x].item[LINEMATE] -= req.linemate;
    server->world.map[client->player.pos_y][client->player.pos_x].item[MENDIANE] -= req.mendiane;
    server->world.map[client->player.pos_y][client->player.pos_x].item[PHIRAS] -= req.phiras;
    server->world.map[client->player.pos_y][client->player.pos_x].item[SIBUR] -= req.sibur;
    server->world.map[client->player.pos_y][client->player.pos_x].item[THYSTAME] -= req.thystame;
    bct_reply(server, client->player.pos_x, client->player.pos_y);
}

static bool is_part_of_elevation(client_t *client, client_t *mate)
{
    node_t *current = client->incentation_mate;

    if (client->incentation_mate == NULL) {
        return false;
    }
    do {
        if ((*GET_DATA(current, client_t *))->player.id == mate->player.id) {
            return true;
        }
        current = current->next;
    } while (current != client->incentation_mate);
    return false;
}

bool check_elevation_req(client_t *client, server_t *server, int level, bool last_check)
{
    elevation_requirement_t req = elevation_requirement[level - 1];

    int nb_player = 0;

    if (server->world.map[client->player.pos_y][client->player.pos_x].item[DERAUMERE] < req.deraumere)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[LINEMATE] < req.linemate)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[MENDIANE] < req.mendiane)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[PHIRAS] < req.phiras)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[SIBUR] < req.sibur)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[THYSTAME] < req.thystame)
        return false;
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0
        && server->clients[i].player.id != client->player.id &&
        server->clients[i].player.pos_x == client->player.pos_x &&
        server->clients[i].player.pos_y == client->player.pos_y &&
        server->clients[i].player.level == client->player.level &&
        ((last_check && is_part_of_elevation(client, &server->clients[i]))
        || (!last_check && !server->clients[i].in_incentation && server->clients[i].incentation_mate == NULL))) {
            nb_player += 1;
        }
    }
    if (nb_player < req.nb_players) {
        return false;
    }
    return true;
}

static void cancel_elevation(client_t *client)
{
    node_t *current = client->incentation_mate;

    if (client->incentation_mate == NULL) {
        return;
    }
    do {
        (*GET_DATA(current, client_t *))->in_incentation = false;
        send_msg_client((*GET_DATA(current, client_t *))->fd, "ko\n");
        current = current->next;
    } while (current != client->incentation_mate);
    free_linked_list(&client->incentation_mate);
}

static void end_elevation(server_t *server, client_t *client)
{
    node_t *current = client->incentation_mate;
    char buffer[100] = {0};

    client->player.level += 1;
    snprintf(buffer, sizeof(buffer), "Current level: %d\n", client->player.level);
    send_msg_client(client->fd, buffer);
    if (client->incentation_mate == NULL) {
        return;
    }
    do {
        (*GET_DATA(current, client_t *))->player.level += 1;
        send_msg_client((*GET_DATA(current, client_t *))->fd, buffer);
        plv_reply(server, (*GET_DATA(current, client_t *)));
        current = current->next;
    } while (current != client->incentation_mate);
    free_linked_list(&client->incentation_mate);
}

static team_t *condition_win(server_t *server)
{
    int nb_player_lvl_8 = 0;

    for (int i = 0; i < server->team_count; ++i) {
        for (int j = 0; j < MAX_CLIENT; ++j) {
            if (server->clients[j].fd != 0 && server->clients[j].player.team == &server->team_list[i]
            && server->clients[j].player.level == 8) {
                nb_player_lvl_8 += 1;
            }
        }
        if (nb_player_lvl_8 >= 6) {
            return &server->team_list[i];
        }
        nb_player_lvl_8 = 0;
    }
    return NULL;
}

void incatation_cmd(char *, client_t *client, server_t *server)
{
    team_t *winning_team = NULL;

    if (check_elevation_req(client, server, client->player.level, true) == false) {
        cancel_elevation(client);
        send_msg_client(client->fd, "ko\n");
        pie_reply(server, client, false);
        return;
    }
    pie_reply(server, client, true);
    plv_reply(server, client);
    remove_elevation_req(client, server, client->player.level);
    end_elevation(server, client);
    winning_team = condition_win(server);
    if (winning_team) {
        seg_reply(server, winning_team);
        server->end_game = true;
    }
}
