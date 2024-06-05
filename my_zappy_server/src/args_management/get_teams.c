/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** get_teams
*/

#include "zappy_server.h"

void get_clients_nb(const char **argv, server_t *server, int i)
{
    if (strcmp(argv[i], args[4]) == 0) {
        if (argv[i + 1] == NULL) {
            my_error("Error: Clients must be specified", 84);
        }
        if (!my_str_only_cont(argv[i + 1], "0123456789")) {
            my_error("Error: Clients must be a number", 84);
        }
        server->opt.client_nb = atoi(argv[i + 1]);
    }
}

static bool is_team_name_taken(const char *name, game_t *game)
{
    for (int j = 0; j < game->team_count; j++) {
        if (strcmp(game->team_list[j].name, name) == 0) {
            return true;
        }
    }
    return false;
}

static bool is_valid_team_name(const char *name)
{
    for (int i = 0; name[i] != '\0'; ++i) {
        if (!isalnum(name[i])) {
            return false;
        }
    }
    return true;
}

static void get_teams_name_error(const char **argv, server_t *server, int i)
{
    if (strlen(argv[i]) > MAX_TEAMNAME_SIZE) {
        my_error("Error: Team name is too long", 84);
    }
    if (is_team_name_taken(argv[i], &server->game)) {
        my_error("Error: Team name already taken", 84);
    }
    if (strcmp(argv[i], "GRAPHIC") == 0) {
        my_error("Error: Team name cannot be GRAPHIC", 84);
    }
    if (!is_valid_team_name(argv[i])) {
        my_error("Error: Team name must be alphanumeric", 84);
    }
}

void get_teams_name(const char **argv, server_t *server, int i, int argc)
{
    for (i = i + 1; i < argc && argv[i][0] != '-'; i++) {
        get_teams_name_error(argv, server, i);
        strcpy(server->game.team_list[server->game.team_count].name, argv[i]);
        server->game.team_list[server->game.team_count].
        remaining_spot = server->opt.client_nb;
        server->game.team_list[server->game.team_count].
        player_max = 0;
        server->game.team_count += 1;
    }
    if (server->game.team_count == 0 ||
        !strcmp(server->game.team_list[0].name, "")) {
        my_error("Error: No team name specified", 84);
    }
}
