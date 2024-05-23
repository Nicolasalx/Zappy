/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_player
*/

#include "zappy_server.h"

void init_player(client_t *client, server_t *server)
{
    char buffer[100] = {0};

    client->player.inventory[FOOD] = 10;
    client->player.id = server->player_count;
    server->player_count += 1;
    client->player.team->remaining_place -= 1;
    sprintf(buffer, "%d\n", client->player.team->remaining_place);
    send_msg_client(client->fd, buffer);
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%d %d\n", server->world.size_x, server->world.size_y);
    send_msg_client(client->fd, buffer);
    memset(buffer, 0, sizeof(buffer));
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].is_graphic == true) {
            snprintf(buffer, sizeof(buffer), "pnw %d %d %d %d %d %s\n", client->player.id, client->player.pos_x, client->player.pos_y, client->player.orientation[NORTH], client->player.level, client->player.team->name);
            send_msg_client(server->clients[i].fd, buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }
}
