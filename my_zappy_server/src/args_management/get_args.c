/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** get_args
*/

#include "zappy_server.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void set_args(server_t *server)
{
    server->args.port = -1;
    server->args.width = -1;
    server->args.height = -1;
    server->args.client_nb = -1;
    server->args.freq = -1;
    server->args.team_count = 0;
    for (int i = 0; i < MAX_TEAM_NB; i++) {
        server->args.teams[i] = NULL;
    }
}

void get_args(int argc, const char **argv, server_t *server)
{
    const char *args[] = {"-p", "-x", "-y", "-c", "-f"};

    set_args(server);
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
        my_exit(0);
    }
    for (int i = 1; i < argc; i++) {
        get_teams_name(argv, server, i, argc);
        get_port_and_freq(argv, server, i, args);
        get_map_size(argv, server, i, args);
        get_clients_nb(argv, server, i, args);
    }
    check_arg_validity(server);
}

