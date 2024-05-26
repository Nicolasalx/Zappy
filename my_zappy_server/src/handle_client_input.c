/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_client_input
*/

#include "zappy_server.h"

static void eggs_info(server_t *server)
{
    char buffer[100] = {0};
    node_t *current = NULL;

    for (int i = 0; i < server->team_count; ++i) {
        current = server->team_list[i].egg_list;
        if (server->team_list[i].egg_list == NULL) {
            return;
        }
        do {
            snprintf(buffer, sizeof(buffer), "%d %d %d\n",
            GET_DATA(current, egg_t)->nb, GET_DATA(current, egg_t)->pos_x,
            GET_DATA(current, egg_t)->pos_y);
            smg_reply(server, buffer);
            memset(buffer, 0, sizeof(buffer));
            if (server->team_list[i].egg_list == NULL) {
                return;
            }
            current = current->next;
        } while (current != server->team_list[i].egg_list);
    }
}

static void handle_new_graphic_client(server_t *server, client_t *client)
{
    char buffer[100] = {0};

    client->is_graphic = true;
    msz_cmd(0, NULL, client, server);
    sgt_cmd(0, NULL, client, server);
    mct_cmd(0, NULL, client, server);
    tna_cmd(0, NULL, client, server);
    eggs_info(server);
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].player.team) {
            snprintf(buffer, sizeof(buffer), "pnw %d %d %d %d %d %s\n",
                server->clients[i].player.id, server->clients[i].player.pos_x,
                server->clients[i].player.pos_y,
                server->clients[i].player.orientation + 1,
                server->clients[i].player.level,
                server->clients[i].player.team->name);
            send_msg_client(client->fd, buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }
}

static void handle_new_player_client(server_t *server, client_t *client, char *cmd)
{
    char buff[MAX_TEAMNAME_SIZE + 2] = {0};

    for (int i = 0; i < server->team_count; ++i) {
        strcpy(buff, server->team_list[i].name);
        strcat(buff, "\n");
        if (strcmp(cmd, buff) == 0) {
            client->player.team = &server->team_list[i];
            init_player(client, server);
            return;
        }
    }
    send_msg_client(client->fd, "ko (not logged in)\n");
}

void handle_client_input(server_t *server, client_t *client, char *cmd)
{
    if (server->end_game) {
        send_msg_client(client->fd, "End of Game\n");
        return;
    }
    if (client->is_graphic) {
        handle_gui_input(server, client, cmd);
    } else if (client->player.team) {
        handle_ai_input(server, client, cmd);
    } else {
        if (strcmp(cmd, "GRAPHIC\n") == 0) {
            handle_new_graphic_client(server, client);
        } else {
            handle_new_player_client(server, client, cmd);
        }
    }
}
