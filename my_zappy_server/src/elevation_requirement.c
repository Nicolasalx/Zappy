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

    server->world.map[client->player.pos_y][client->player.pos_x]
        .item[DERAUMERE] -= req.deraumere;
    server->world.map[client->player.pos_y][client->player.pos_x]
        .item[LINEMATE] -= req.linemate;
    server->world.map[client->player.pos_y][client->player.pos_x]
        .item[MENDIANE] -= req.mendiane;
    server->world.map[client->player.pos_y][client->player.pos_x]
        .item[PHIRAS] -= req.phiras;
    server->world.map[client->player.pos_y][client->player.pos_x]
        .item[SIBUR] -= req.sibur;
    server->world.map[client->player.pos_y][client->player.pos_x]
        .item[THYSTAME] -= req.thystame;
    bct_reply(server, client->player.pos_x, client->player.pos_y);
}

static bool check_elevation_item_req(server_t *server,
    client_t *client, elevation_requirement_t req)
{
    if (server->world.map[client->player.pos_y][client->player.pos_x].
    item[DERAUMERE] < req.deraumere)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].
    item[LINEMATE] < req.linemate)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].
    item[MENDIANE] < req.mendiane)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].
    item[PHIRAS] < req.phiras)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].
    item[SIBUR] < req.sibur)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].
    item[THYSTAME] < req.thystame)
        return false;
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
        || (!last_check && !server->clients[i].in_incentation
        && server->clients[i].incentation_mate == NULL))) {
            nb_player += 1;
        }
    }
    if (nb_player < req.nb_players)
        return false;
    return true;
}
