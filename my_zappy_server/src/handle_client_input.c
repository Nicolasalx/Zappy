/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_client_input
*/

#include "zappy_server.h"

static void handle_new_graphic_client(server_t *server, client_t *client)
{
    client->is_graphic = true;
    msz_cmd(0, NULL, client, server);
    sgt_cmd(0, NULL, client, server);
    mct_cmd(0, NULL, client, server);
    tna_cmd(0, NULL, client, server);
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
    printf("client send: %s\n", cmd);

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
