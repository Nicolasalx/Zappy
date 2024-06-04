/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** level_cmd
*/

#include "zappy_server.h"

void pause_cmd(int, char **, server_t *server)
{
    if (server->opt.pause_game == true) {
        printf("Game already paused\n");
        return;
    }
    server->opt.pause_game = true;
    smg_reply(server, "Game paused");
    printf("Game paused\n");
}
