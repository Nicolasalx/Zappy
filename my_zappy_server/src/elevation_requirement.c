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

static bool check_elevation_item_req_4(server_t *server, client_t *client,
    elevation_requirement_t req)
{
    bool check = true;

    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[DERAUMERE] < req.deraumere) {
        if (server->opt.is_debug == true)
            printf("- %d deraumere missing\n", req.deraumere -
                server->game.world.map[client->player.pos_y]
                [client->player.pos_x].item[DERAUMERE]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[THYSTAME] < req.thystame) {
        if (server->opt.is_debug == true)
            printf("- %d thystame missing\n", req.thystame -
                server->game.world.map[client->player.pos_y]
                [client->player.pos_x].item[THYSTAME]);
        check = false;
    }
    return check;
}

static bool check_elevation_item_req_3(server_t *server, client_t *client,
    elevation_requirement_t req)
{
    bool check = true;

    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[LINEMATE] < req.linemate) {
        if (server->opt.is_debug == true)
            printf("- %d linemate missing\n", req.linemate -
                server->game.world.map[client->player.pos_y]
                [client->player.pos_x].item[LINEMATE]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[MENDIANE] < req.mendiane) {
        if (server->opt.is_debug == true)
            printf("- %d mendiane missing\n", req.mendiane -
                server->game.world.map[client->player.pos_y]
                [client->player.pos_x].item[MENDIANE]);
        check = false;
    }
    return check;
}

static bool check_elevation_item_req_2(server_t *server, client_t *client,
    elevation_requirement_t req)
{
    bool check = true;

    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[PHIRAS] < req.phiras) {
        if (server->opt.is_debug == true)
            printf("- %d phiras missing\n", req.phiras -
                server->game.world.map[client->player.pos_y]
                    [client->player.pos_x].item[PHIRAS]);
        check = false;
    }
    if (server->game.world.map[client->player.pos_y][client->player.pos_x].
    item[SIBUR] < req.sibur) {
        if (server->opt.is_debug == true)
            printf("- %d sibur missing\n", req.sibur -
                server->game.world.map[client->player.pos_y]
                    [client->player.pos_x].item[SIBUR]);
        check = false;
    }
    return check;
}

static bool check_elevation_item_req(server_t *server,
    client_t *client, elevation_requirement_t req)
{
    char buffer[100] = {0};
    bool check = true;

    if (!check_elevation_item_req_2(server, client, req))
        check = false;
    if (!check_elevation_item_req_3(server, client, req))
        check = false;
    if (!check_elevation_item_req_4(server, client, req))
        check = false;
    if (!check) {
        if (server->opt.is_debug == true) {
            printf("[Debug] Incantation failed"
                " because ressources are missing\n");
        }
        return false;
    }
    return true;
}

static bool check_number_player(server_t *server, int nb_player,
    elevation_requirement_t req)
{
    if (nb_player < req.nb_players) {
        if (server->opt.is_debug == true) {
            printf("[Debug] Incantation players requirements failed:\n- %d "
                "missing players", req.nb_players - nb_player);
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
    if (check_number_player(server, nb_player, req) == false)
        return false;
    return true;
}
