/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** level_cmd
*/

#include "zappy_server.h"

static void send_player_level_reply(
    server_t *server, team_t *winning_team)
{
    if (winning_team) {
        seg_reply(server, winning_team);
        server->end_game = true;
    }
}

static bool level_up_player(server_t *server, int id, int level)
{
    team_t *winning_team = NULL;

    for (int i = 0; i < MAX_CLIENT; i++) {
        if (server->clients[i].fd != 0 && server->clients[i].player.id == id
        && server->clients[i].is_graphic == false
        && server->clients[i].player.team) {
            server->clients[i].player.level = level;
            winning_team = condition_win(server);
            send_player_level_reply(server, winning_team);
            return true;
        }
    }
    return false;
}

void level_cmd(int, char **argv, server_t *server)
{
    int id = atoi(argv[0]);
    int level = atoi(argv[1]);

    if (!my_str_only_cont(argv[0], "0123456789")
    || !my_str_only_cont(argv[1], "0123456789")
    || level < 1 || level > 8) {
        printf("Error: invalid argument\n");
        return;
    }
    if (level_up_player(server, id, level)) {
        return;
    }
    printf("Error: client not found\n");
}
