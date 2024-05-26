/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_cmd
*/

#include "zappy_server.h"

static bool eject_egg(client_t *client, server_t *server, int i)
{
    node_t *current = NULL;

    current = server->team_list[i].egg_list;
    if (server->team_list[i].egg_list == NULL) {
        return true;
    }
    do {
        if (GET_DATA(current, egg_t)->pos_x == client->player.pos_x
        && GET_DATA(current, egg_t)->pos_y == client->player.pos_y) {
            edi_reply(server, &server->clients[i], GET_DATA(current, egg_t));
            delete_node(&server->team_list[i].egg_list, current);
        }
        if (server->team_list[i].egg_list == NULL) {
            return true;
        }
        current = current->next;
    } while (current != server->team_list[i].egg_list);
    return false;
}

static void eject_egg_from_tile(client_t *client, server_t *server)
{
    for (int i = 0; i < server->team_count; ++i) {
        if (eject_egg(client, server, i)) {
            return;
        }
    }
}

static void eject_player_in_orientation(server_t *server,
    client_t *client, int i)
{
    if (client->player.orientation == NORTH) {
        server->clients[i].player.pos_y = (server->clients[i].player.pos_y
            - 1 + server->world.size_y) % server->world.size_y;
        send_msg_client(server->clients[i].fd, "eject: 3\n");
    }
    if (client->player.orientation == EAST) {
        server->clients[i].player.pos_x = (server->clients[i].player.pos_x
            + 1) % server->world.size_x;
        send_msg_client(server->clients[i].fd, "eject: 4\n");
    }
    if (client->player.orientation == SOUTH) {
        server->clients[i].player.pos_y = (server->clients[i].player.pos_y
            + 1) % server->world.size_y;
        send_msg_client(server->clients[i].fd, "eject: 1\n");
    }
    if (client->player.orientation == WEST) {
        server->clients[i].player.pos_x = (server->clients[i].player.pos_x
            - 1 + server->world.size_x) % server->world.size_x;
        send_msg_client(server->clients[i].fd, "eject: 2\n");
    }
}

void eject_cmd(char *, client_t *client, server_t *server)
{
    bool ejected = false;

    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic != true
        && server->clients[i].player.pos_x == client->player.pos_x
        && server->clients[i].player.pos_y == client->player.pos_y
        && server->clients[i].player.id != client->player.id) {
            eject_player_in_orientation(server, client, i);
            pex_reply(server, &server->clients[i]);
            ppo_reply(server, &server->clients[i]);
            eject_egg_from_tile(client, server);
            ejected = true;
        }
    }
    if (ejected)
        send_msg_client(client->fd, "ok\n");
    else
        send_msg_client(client->fd, "ko\n");
}
