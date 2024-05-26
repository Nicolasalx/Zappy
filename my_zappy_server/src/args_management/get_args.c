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

static void check_immortal(const char **argv,
    server_t *server, int i, const char **args)
{
    if (strcmp(argv[i], args[5]) == 0) {
        server->is_immortal = true;
        printf("Immortal set to true\n");
    }
}

void get_args(int argc, const char **argv, server_t *server)
{
    const char *args[] = {"-p", "-x", "-y", "-c", "-f", "--immortal"};

    set_args(server);
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("USAGE: ./zappy_server -p port -x width -y "
        "height -n name1 name2 ... -c clientsNb -f freq\n");
        my_exit(0);
    }
    for (int i = 1; i < argc; i++) {
        get_teams_name(argv, server, i, argc);
        get_port_and_freq(argv, server, i, args);
        get_map_size(argv, server, i, args);
        get_clients_nb(argv, server, i, args);
        check_immortal(argv, server, i, args);
    }
    check_arg_validity(server);
}
