/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_player
*/

#include "zappy_server.h"

static void choose_random_egg(server_t *server,
    client_t *client, node_t *chosen_one)
{
    int nb_egg = my_listlen(client->player.team->egg_list);

    while (true) {
        if ((rand() % nb_egg) == 0) {
            client->player.pos_x = GET_DATA(chosen_one, egg_t)->pos_x;
            client->player.pos_y = GET_DATA(chosen_one, egg_t)->pos_y;
            client->player.orientation = rand() % 4;
            ebo_reply(server, GET_DATA(chosen_one, egg_t));
            edi_reply(server, client, GET_DATA(chosen_one, egg_t));
            delete_node(&client->player.team->egg_list, chosen_one);
            return;
        }
        chosen_one = chosen_one->next;
    }
}

static bool search_spawn_egg(client_t *client, server_t *server)
{
    node_t *chosen_one = client->player.team->egg_list;

    if (client->player.team->remaining_spot >= 0
    && client->player.team->egg_list
    && client->player.team->player_max <= MAX_PLAYER_CONNECTED_PER_TEAM) {
        choose_random_egg(server, client, chosen_one);
        return true;
    } else {
        send_msg_client(client->fd, "ko\n");
        remove_client(client);
        return false;
    }
}

void init_player(client_t *client, server_t *server)
{
    char buffer[100] = {0};

    client->player.team->remaining_spot -= 1;
    client->player.team->player_max += 1;
    if (!search_spawn_egg(client, server)) {
        return;
    }
    client->player.inventory[FOOD] = 10;
    client->player.level = 1;
    client->player.id = server->game.player_count;
    server->game.player_count += 1;
    snprintf(buffer, sizeof(buffer), "%d\n",
        client->player.team->remaining_spot);
    send_msg_client(client->fd, buffer);
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "%d %d\n",
        server->game.world.size_x, server->game.world.size_y);
    send_msg_client(client->fd, buffer);
    pnw_reply(server, client);
    pin_reply(server, client);
}
