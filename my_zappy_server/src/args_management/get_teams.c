/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** get_teams
*/

#include "zappy_server.h"

void get_clients_nb(const char **argv, server_t *server, int i, const char **args)
{
    if (strcmp(argv[i], args[3]) == 0) {
        if (my_str_only_cont(argv[i + 1], "0123456789")) {
            server->client_nb = atoi(argv[i + 1]);
        }
        else {
            my_error("Error: Clients must be a number", 84);
        }
    }
}

void get_teams_name(const char **argv, server_t *server, int i, int argc)
{
    if (strcmp(argv[i], "-n") == 0) {
        for (i = i + 1; i < argc && argv[i][0] != '-' && server->team_count < MAX_TEAM_NB; i++) {
            strcpy(server->team_list[server->team_count].name, argv[i]);
            server->team_list[server->team_count].remaining_place = server->client_nb;
            server->team_count += 1;
        }
        i -= 1;
    }
}



