/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_server.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void check_arg_validity(server_t *server, int team_count)
{
    if (server->args.port == -1 || server->args.width == -1
    || server->args.height == -1 || server->args.client_nb == -1
    || server->args.freq == -1 || team_count == 0) {
        printf("Error: Invalid args\n");
        my_exit(84);
    }
    if (server->args.port < 0 || server->args.port > MAX_PORT_NB) {
        printf("Error: Invalid port\n");
        my_exit(84);
    }
    if (server->args.width <= 0) {
        printf("Error: Width must be superior to 0\n");
        my_exit(84);
    }
    if (server->args.height <= 0) {
        printf("Error: Height must be superior to 0\n");
        my_exit(84);
    }
    if (server->args.client_nb <= 0) {
        printf("Error: Clients must be superior to 0\n");
        my_exit(84);
    }
    if (server->args.freq <= 0) {
        printf("Error: Frequency must be superior to 0\n");
        my_exit(84);
    }
}

const void set_args(server_t *server)
{
    server->args.port = -1;
    server->args.width = -1;
    server->args.height = -1;
    server->args.client_nb = -1;
    server->args.freq = -1;
    for (int i = 0; i < MAX_TEAM_NB; i++) {
        server->args.teams[i] = NULL;
    }
}

void get_args(int argc, const char **argv, server_t *server)
{
    const char *args[] = {"-p", "-x", "-y", "-c", "-f"};
    int team_count = 0;

    set_args(server);
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
        my_exit(0);
    }
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            for (i = i + 1; i < argc && argv[i][0] != '-'; i++) {
                server->args.teams[team_count] = strdup(argv[i]);
                team_count += 1;
            }
            server->args.teams[team_count] = NULL;
            i -= 1;
        }
        if (strcmp(argv[i], args[0]) == 0) {
            server->args.port = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], args[1]) == 0) {
            server->args.width = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], args[2]) == 0) {
            server->args.height = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], args[3]) == 0) {
            server->args.client_nb = atoi(argv[i + 1]);
        }
        if (strcmp(argv[i], args[4]) == 0) {
            server->args.freq = atoi(argv[i + 1]);
        }
    }
    check_arg_validity(server, team_count);
    printf("port: %d\n", server->args.port);
    printf("width: %d\n", server->args.width);
    printf("height: %d\n", server->args.height);
    printf("client_nb: %d\n", server->args.client_nb);
    printf("freq: %d\n", server->args.freq);

    for (int i = 0; server->args.teams[i] != NULL; i++) {
        printf("team: %s\n", server->args.teams[i]);
    }
}

