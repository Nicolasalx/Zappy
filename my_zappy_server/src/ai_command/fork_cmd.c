/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** fork_cmd
*/

#include "zappy_server.h"

void fork_cmd(char *, client_t *client, server_t *server)
{
    egg_t *new_egg = my_calloc(sizeof(egg_t));

    new_egg->pos_x = client->player.pos_x;
    new_egg->pos_y = client->player.pos_y;
    new_egg->nb = server->game.egg_count;
    ++server->game.egg_count;
    append_node(&client->player.team->egg_list, create_node(new_egg));
    ++client->player.team->remaining_spot;
    pfk_reply(server, client);
    enw_reply(server, client, new_egg);
    send_msg_client(client->fd, "ok\n");
    if (server->opt.is_debug == true)
        printf("[Debug] Player %d forked, new egg at position: X:%d Y:%d\n", client->player.id, new_egg->pos_x, new_egg->pos_y);
}
