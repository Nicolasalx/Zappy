/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** elevation_requirement
*/

#include "zappy_server.h"

const elevation_requirement_t elevation_req[] =
{
    {1, 1 - 1, 1, 0, 0, 0, 0, 0},
    {2, 2 - 1, 1, 1, 1, 0, 0, 0},
    {3, 2 - 1, 2, 0, 1, 0, 2, 0},
    {4, 4 - 1, 1, 1, 2, 0, 1, 0},
    {5, 4 - 1, 1, 2, 1, 3, 0, 0},
    {6, 6 - 1, 1, 2, 3, 0, 1, 0},
    {7, 6 - 1, 2, 2, 2, 2, 2, 1}
};

void remove_elevation_req(client_t *client, server_t *server, int level)
{
    elevation_requirement_t req = elevation_req[level - 1];

    server->game.world.map[client->player.pos_y][client->player.pos_x]
        .item[DERAUMERE] -= req.deraumere;
    server->game.world.map[client->player.pos_y][client->player.pos_x]
        .item[LINEMATE] -= req.linemate;
    server->game.world.map[client->player.pos_y][client->player.pos_x]
        .item[MENDIANE] -= req.mendiane;
    server->game.world.map[client->player.pos_y][client->player.pos_x]
        .item[PHIRAS] -= req.phiras;
    server->game.world.map[client->player.pos_y][client->player.pos_x]
        .item[SIBUR] -= req.sibur;
    server->game.world.map[client->player.pos_y][client->player.pos_x]
        .item[THYSTAME] -= req.thystame;
    if (server->opt.is_debug == true) {
        printf("[Debug] Elevation requirements removed\n");
    }
    bct_reply(server, client->player.pos_x, client->player.pos_y);
}

static bool check_elevation_item_req(server_t *server,
    client_t *client, elevation_requirement_t req)
{
    char buffer[100] = {0};
    bool check = true;

    snprintf(buffer, sizeof(buffer), "Incantation requirements failed:\n");
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[DERAUMERE] < req.deraumere) {
        snprintf(buffer, sizeof(buffer), "- %d deraumere missing\n", req.deraumere - server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[DERAUMERE]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[LINEMATE] < req.linemate) {
        snprintf(buffer, sizeof(buffer), "- %d linemate missing\n", req.linemate - server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[LINEMATE]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[MENDIANE] < req.mendiane) {
        snprintf(buffer, sizeof(buffer), "- %d mendiane missing\n", req.mendiane - server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[MENDIANE]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[PHIRAS] < req.phiras) {
        snprintf(buffer, sizeof(buffer), "- %d phiras missing\n", req.phiras - server->game.world.map[client->player.pos_y][client->player.pos_x].item[PHIRAS]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[SIBUR] < req.sibur) {
        snprintf(buffer, sizeof(buffer), "- %d sibur missing\n", req.sibur - server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[SIBUR]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[THYSTAME] < req.thystame) {
        snprintf(buffer, sizeof(buffer), "- %d thystame missing\n", req.thystame - server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[THYSTAME]);
        check = false;
    }
    if (!check) {
        if (server->opt.is_debug == true) {
            printf("[Debug] %s\n", buffer);
        }
        return false;
    }
    return true;
}

bool check_elevation_req(client_t *client,
    server_t *server, int level, bool last_check)
{
    elevation_requirement_t req = elevation_req[level - 1];
    int nb_player = 0;

    if (!check_elevation_item_req(server, client, req))
        return false;
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0
        && server->clients[i].player.id != client->player.id &&
        server->clients[i].player.pos_x == client->player.pos_x &&
        server->clients[i].player.pos_y == client->player.pos_y &&
        server->clients[i].player.level == client->player.level &&
        ((last_check && is_part_of_elevation(client, &server->clients[i]))
        || (!last_check && !server->clients[i].player.in_incentation
        && server->clients[i].player.incentation_mate == NULL))) {
            nb_player += 1;
        }
    }
    if (nb_player < req.nb_players) {
        if (server->opt.is_debug == true) {
            printf("\n");
        }
        return false;
    }
    return true;
}
