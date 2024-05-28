/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** consume_food
*/

#include "zappy_server.h"

static void check_player_death(client_t *client, server_t *server)
{
    client->player.food_time_unit += 1;
    if (client->player.food_time_unit > 126) {
        client->player.food_time_unit = 0;
        client->player.inventory[FOOD] -= 1;
        if (client->player.inventory[FOOD] <= 0) {
            send_msg_client(client->fd, "dead\n");
            printf(YELLOW("A client has been closed")"\n");
            pdi_reply(server, client);
            remove_client(client);
        }
        pin_reply(server, client);
    }
}

void consume_food(server_t *server)
{
    if (server->is_immortal) {
        return;
    }
    for (int i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd == 0
        || server->clients[i].is_graphic
        || !server->clients[i].player.team) {
            continue;
        }
        check_player_death(&server->clients[i], server);
    }
}
