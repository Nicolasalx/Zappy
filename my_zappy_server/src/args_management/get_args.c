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
    server->game.world.size_x = -1;
    server->game.world.size_y = -1;
    server->opt.client_nb = -1;
    server->opt.freq = -1;
    server->game.team_count = 0;
    server->game.player_count = 0;
    server->game.egg_count = 0;
    server->opt.end_game = false;
    server->opt.pause_game = false;
    for (int i = 0; i < MAX_CLIENT; i++) {
        server->clients[i].player.is_graphic = false;
        server->clients[i].player.id = -1;
    }
}

static bool is_valid_argument(const char *arg)
{
    for (int i = 0; i < 6; ++i) {
        if (strcmp(arg, args[i]) == 0) {
            return true;
        }
    }
    return false;
}

static bool check_args(const char **argv, int argc, server_t *server, int i)
{
    if (argv[i][0] == '-' && is_valid_argument(argv[i])) {
        if (strcmp(argv[i], args[3]) == 0) {
            get_teams_name(argv, server, i, argc);
            return false;
        }
        if (argv[i] != NULL) {
            get_port_and_freq(argv, server, i);
            get_map_size(argv, &server->game, i);
            get_clients_nb(argv, server, i);
            return true;
        }
    }
    my_error("Error: Invalid argument", 84);
    return false;
}

void get_args(int argc, const char **argv, server_t *server)
{
    set_args(server);
    if (argc == 2 && !strcmp(argv[1], "-help")) {
        printf("USAGE: ./zappy_server -p port -x width -y "
        "height -n name1 name2 ... -c clientsNb -f freq\n");
        my_exit(0);
    }
    for (int i = 1; i < argc; i++) {
        if (check_args(argv, argc, server, i)) {
            i++;
        } else {
            i += server->game.team_count;
        }
    }
    check_arg_validity(server);
}
