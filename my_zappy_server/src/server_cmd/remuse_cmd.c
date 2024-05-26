/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** resume_cmd
*/

#include "zappy_server.h"

void resume_cmd(int, char **, server_t *server)
{
    if (server->pause_game == false) {
        printf("Game already resumed\n");
        return;
    }
    server->pause_game = false;
    smg_reply(server, "Game resumed");
    printf("Game resumed\n");
}
