/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** server_info
*/

#include "zappy_server.h"

static void get_port(const char **argv, server_t *server, int i, const char **args)
{
    if (strcmp(argv[i], args[0]) == 0) {
        if (my_str_only_cont(argv[i + 1], "0123456789")) {
            server->port = atoi(argv[i + 1]);
        }
        else {
            my_error("Error: Port must be a number", 84);
        }
    }
}

static void get_frequency(const char **argv, server_t *server, int i, const char **args)
{
    if (strcmp(argv[i], args[4]) == 0) {
        if (my_str_only_cont(argv[i + 1], "0123456789")) {
            server->freq = atoi(argv[i + 1]);
        }
        else {
            my_error("Error: Frequency must be a number", 84);
        }
    }
}

void get_port_and_freq(const char **argv, server_t *server, int i, const char **args)
{
    get_port(argv, server, i, args);
    get_frequency(argv, server, i, args);
}