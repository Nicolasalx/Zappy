/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** debug_cmd
*/

#include "zappy_server.h"

void debug_cmd(int, char **argv, server_t *server)
{
    if (strcmp(argv[0], "true") == 0) {
        printf("Server is now in debug mode\n");
        server->opt.is_debug = true;
    } else if (strcmp(argv[0], "false") == 0) {
        printf("Server is not anymore in debug mode\n");
        server->opt.is_debug = false;
    } else {
        printf("Error: invalid argument\n");
    }
}
