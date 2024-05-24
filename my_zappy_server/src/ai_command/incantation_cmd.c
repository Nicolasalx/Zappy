/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation_cmd
*/

#include "zappy_server.h"

static bool check_elevation_req(client_t *client, server_t *server, int level)
{
    elevation_requirement_t req = elevation_requirement[level - 1];

    if (server->world.map[client->player.pos_y][client->player.pos_x].item[DERAUMERE] > req.deraumere)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[LINEMATE] > req.linemate)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[MENDIANE] > req.mendiane)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[PHIRAS] > req.phiras)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[SIBUR] > req.sibur)
        return false;
    if (server->world.map[client->player.pos_y][client->player.pos_x].item[THYSTAME] > req.thystame)
        return false;
    // check si il y a assez de joueurs de la team sur la case du joueur qui a fait la commande
    return true;
}

void incatation_cmd(char *, client_t *client, server_t *server)
{
    char buffer[100] = {0};
    if (check_elevation_req(client, server, client->player.level + 1) == false) {
        send_msg_client(client->fd, "ko\n");
        return;
    }
    client->player.level += 1;
    snprintf(buffer, sizeof(buffer), "Elevation underway\nCurrent level: %d\n", client->player.level);
    send_msg_client(client->fd, buffer);

}
