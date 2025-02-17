/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** kill_cmd
*/

#include "zappy_server.h"

void immortal_cmd(int, char **argv, server_t *server)
{
    if (strcmp(argv[0], "true") == 0) {
        printf("Players are now immortal\n");
        server->opt.is_immortal = true;
    } else if (strcmp(argv[0], "false") == 0) {
        printf("Players are now mortal\n");
        server->opt.is_immortal = false;
    } else {
        printf("Error: invalid argument\n");
    }
}
