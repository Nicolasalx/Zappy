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

#include "zappy_server.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zappy_server.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_arg_validity(int argc, const char **argv, server_t *server)
{
    char args[30][30] = {"-p", "-x", "-y", "-c", "-f"};
    int team_count = 0;

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

    printf("port: %d\n", server->args.port);
    printf("width: %d\n", server->args.width);
    printf("height: %d\n", server->args.height);
    printf("client_nb: %d\n", server->args.client_nb);
    printf("freq: %d\n", server->args.freq);

    for (int i = 0; server->args.teams[i] != NULL; i++) {
        printf("team: %s\n", server->args.teams[i]);
    }
}

