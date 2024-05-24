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
        if (argv[i + 1] == NULL) {
            my_error("Error: Clients must be specified", 84);
        }
        if (!my_str_only_cont(argv[i + 1], "0123456789")) {
            my_error("Error: Clients must be a number", 84);
        }
        server->client_nb = atoi(argv[i + 1]);
    }
}

static bool is_team_name_taken(const char *name, server_t *server)
{
    for (int j = 0; j < server->team_count; j++) {
        if (strcmp(server->team_list[j].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void get_teams_name(const char **argv, server_t *server, int i, int argc)
{
    if (strcmp(argv[i], "-n") == 0) {
        for (i = i + 1; i < argc && argv[i][0] != '-' && server->team_count < MAX_TEAM_NB; i++) {
            if (strlen(argv[i]) > MAX_TEAMNAME_SIZE) {
                my_error("Error: Team name is too long", 84);
            }
            if (is_team_name_taken(argv[i], server)) {
                my_error("Error: Team name already taken", 84);
            }
            strcpy(server->team_list[server->team_count].name, argv[i]);
            server->team_list[server->team_count].remaining_place = server->client_nb;
            server->team_count += 1;
        }
        i -= 1;
    }
}



