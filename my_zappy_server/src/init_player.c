/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_player
*/

#include "zappy_server.h"

static bool search_spawn_egg(client_t *client, server_t *server)
{
    int nb_egg = my_listlen(client->player.team->egg_list);
    node_t *chosen_one = client->player.team->egg_list;

    if (client->player.team->remaining_place > 0 && client->player.team->egg_list) {
        while (true) {
            if ((rand() % nb_egg) == 0) {
                client->player.pos_x = GET_DATA(chosen_one, egg_t)->pos_x;
                client->player.pos_y = GET_DATA(chosen_one, egg_t)->pos_y;
                client->player.orientation = rand() % 4;
                client->player.team->remaining_place -= 1;
                ebo_reply(server, GET_DATA(chosen_one, egg_t));
                // call edi quand un joueur spawn sur l'oeuf?
                // edi_reply(server, client, GET_DATA(chosen_one, egg_t));
                delete_node(&client->player.team->egg_list, chosen_one);
                return true;
            }
            chosen_one = chosen_one->next;
        }
    } else {
        memset(&client->player, 0, sizeof(client->player));
        send_msg_client(client->fd, "ko\n");
        return false;
    }
}

void init_player(client_t *client, server_t *server)
{
    char buffer[100] = {0};

    client->player.inventory[FOOD] = 10;
    client->player.level = 1;
    client->player.id = server->player_count;

    if (!search_spawn_egg(client, server)) {
        return;
    }
    // server->clients[1].player.pos_x = 3;
    // server->clients[1].player.pos_y = 2;
    // server->clients[1].player.orientation = 2;
    // server->clients[2].player.pos_x = 7;
    // server->clients[2].player.pos_y = 1;
    // server->clients[2].player.orientation = 2;
    server->player_count += 1;
    snprintf(buffer, sizeof(buffer), "%d\n", client->player.team->remaining_place);
    send_msg_client(client->fd, buffer);
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "%d %d\n", server->world.size_x, server->world.size_y);
    send_msg_client(client->fd, buffer);
    pnw_reply(server, client);
    pin_reply(server, client);
}
