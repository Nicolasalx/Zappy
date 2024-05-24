/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation_cmd
*/

#include "zappy_server.h"

bool check_elevation_req(client_t *client, server_t *server, int level)
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
        if (server->clients[i].fd != 0 && server->clients[i].player.team == client->player.team) {
            if (server->clients[i].player.pos_x == client->player.pos_x &&
                server->clients[i].player.pos_y == client->player.pos_y &&
                server->clients[i].player.level == client->player.level) {
                nb_player += 1;
            }
        }
    }
    if (nb_player < req.nb_players) {
        return false;
    }
    return true;
}

static void cancel_elevation(server_t *server, client_t *client)
{
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0
            && server->clients[i].player.team == client->player.team) {
            server->clients[i].in_incentation = false;
        }
    }
}

static void end_elevation(server_t *server, client_t *client)
{
    client->in_incentation = false;
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0
        && server->clients[i].player.team == client->player.team
        && server->clients[i].in_incentation) {
            send_msg_client(server->clients[i].fd, "dead\n");
            pdi_reply(server, client);
            remove_client(&server->clients[i]);
        }
    }
}

void incatation_cmd(char *, client_t *client, server_t *server)
{
    char buffer[100] = {0};

    if (check_elevation_req(client, server, client->player.level) == false) {
        cancel_elevation(server, client);
        send_msg_client(client->fd, "ko\n");
        pie_reply(server, client, false);
        return;
    }
    client->player.level += 1;
    end_elevation(server, client);
    snprintf(buffer, sizeof(buffer), "Current level: %d\n", client->player.level);
    send_msg_client(client->fd, buffer);
    pie_reply(server, client, true);
}
