/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
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
    server->port = -1;
    server->world.size_x = -1;
    server->world.size_y = -1;
    server->client_nb = -1;
    server->freq = -1;
    server->team_count = 0;
    server->player_count = 0;
    server->egg_count = 0;
    server->end_game = false;
    server->pause_game = false;
    for (int i = 0; i < MAX_CLIENT; i++) {
        server->clients[i].is_graphic = false;
        server->clients[i].player.id = -1;
    }
}

static bool is_valid_argument(const char *arg)
{
    for (int i = 0; i < 5; ++i) {
        if (strcmp(arg, args[i]) == 0) {
            return true;
        }
    }
    return false;
}

void get_args(int argc, const char **argv, server_t *server)
{
    set_args(server);
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./zappy_server -p port -x width -y "
        "height -n name1 name2 ... -c clientsNb -f freq\n");
        my_exit(0);
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && is_valid_argument(argv[i])) {
            if (strcmp(argv[i], "-n") == 0) {
                get_teams_name(argv, server, i, argc);
                i += server->team_count - 1;
            }
            get_port_and_freq(argv, server, i);
            get_map_size(argv, server, i);
            get_clients_nb(argv, server, i);
            i += 1;
        } else {
            my_error("Error: Invalid argument", 84);
        }
    }
    check_arg_validity(server);
}
