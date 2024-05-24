/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_cmd
*/

#include "zappy_server.h"

static void eject_egg_from_tile(client_t *client, server_t *server)
{
    node_t *current = NULL;

    for (int i = 0; i < server->team_count; ++i) {
        current = server->team_list[i].egg_list;

        if (server->team_list[i].egg_list == NULL) {
            return;
        }
        do {
            if (GET_DATA(current, egg_t)->pos_x == client->player.pos_x
            && GET_DATA(current, egg_t)->pos_y == client->player.pos_y) {
                edi_reply(server, &server->clients[i], GET_DATA(current, egg_t));
                delete_node(&server->team_list[i].egg_list, current);
            }
            if (server->team_list[i].egg_list == NULL) {
                return;
            }
            current = current->next;
        } while (current != server->team_list[i].egg_list);
    }
}

void eject_cmd(char *, client_t *client, server_t *server)
{
    char buffer[100] = {0};

    snprintf(buffer, sizeof(buffer), "eject: %d\n", client->player.orientation);
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd != 0 && server->clients[i].is_graphic != true
        && server->clients[i].player.pos_x == client->player.pos_x
        && server->clients[i].player.pos_y == client->player.pos_y
        && server->clients[i].player.id != client->player.id) {
            switch (client->player.orientation) {
                case NORTH:
                    server->clients[i].player.pos_y = (server->clients[i].player.pos_y - 1 + server->world.size_y) % server->world.size_y;
                    break;
                case EAST:
                    server->clients[i].player.pos_x = (server->clients[i].player.pos_x + 1) % server->world.size_x;
                    break;
                case SOUTH:
                    server->clients[i].player.pos_y = (server->clients[i].player.pos_y + 1) % server->world.size_y;
                    break;
                case WEST:
                    server->clients[i].player.pos_x = (server->clients[i].player.pos_x - 1 + server->world.size_x) % server->world.size_x;
                    break;
            }
            pex_reply(server, &server->clients[i]);
            ppo_reply(server, &server->clients[i]);
            eject_egg_from_tile(client, server);
            send_msg_client(server->clients[i].fd, buffer);
        }
    }
}
