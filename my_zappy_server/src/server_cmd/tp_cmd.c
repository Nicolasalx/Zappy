/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tp_cmd
*/

#include "zappy_server.h"

void tp_cmd(int argc, char **argv, server_t *server)
{
    (void) server;
    printf("argc: %d argv: %s %s %s %s\n", argc, argv[0], argv[1], argv[2], argv[3]);
}
