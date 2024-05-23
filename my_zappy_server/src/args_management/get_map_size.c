/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** get_map_size
*/

#include "zappy_server.h"

static void get_width(const char **argv, server_t *server, int i, const char **args)
{
    if (strcmp(argv[i], args[1]) == 0) {
        if (!my_str_only_cont(argv[i + 1], "0123456789")) {
            my_error("Error: Width must be a number", 84);
        }
        server->world.size_x = atoi(argv[i + 1]);
    }
}

static void get_height(const char **argv, server_t *server, int i, const char **args)
{
    if (strcmp(argv[i], args[2]) == 0) {
        if (!my_str_only_cont(argv[i + 1], "0123456789")) {
            my_error("Error: Height must be a number", 84);
        }
        server->world.size_y = atoi(argv[i + 1]);
    }
}

void get_map_size(const char **argv, server_t *server, int i, const char **args)
{
    get_width(argv, server, i, args);
    get_height(argv, server, i, args);
}