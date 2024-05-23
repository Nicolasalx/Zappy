/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_client_input
*/

#include "zappy_server.h"

void handle_client_input(server_t *server, client_t *client, char *cmd)
{
    char buffer[100] = {0};

    printf("client send: %s\n", cmd);

    if (client->is_graphic) {
        handle_gui_input(server, client, cmd);
    } else if (client->player.team) {
        handle_ai_input(server, client, cmd);
    } else {
        if (strcmp(cmd, "GRAPHIC\n") == 0) {
            client->is_graphic = true;
            msz_cmd(0, NULL, client, server);
            sgt_cmd(0, NULL, client, server);
            mct_cmd(0, NULL, client, server);
            tna_cmd(0, NULL, client, server);
        } else {
            for (int i = 0; i < server->team_count; ++i) {
                if (strlen(cmd) > 1 && strncmp(cmd, server->team_list[i].name, strlen(cmd) - 1) == 0) {
                    client->player.team = &server->team_list[i];
                    init_player(client, server);
                    for (int i = 0; i < MAX_CLIENT; i++) {
                        if (server->clients[i].is_graphic == true) {
                            snprintf(buffer, sizeof(buffer), "pnw %d %d %d %d %d %s\n", client->player.id, client->player.pos_x, client->player.pos_y, client->player.orientation[NORTH], client->player.level, client->player.team->name);
                            send_msg_client(server->clients[i].fd, buffer);
                            memset(buffer, 0, sizeof(buffer));
                        }
                    }
                    return;
                }
            }
            send_msg_client(client->fd, "ko (not logged in)\n");
        }
    }
}
