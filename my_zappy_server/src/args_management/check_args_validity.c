/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_server.h"

static void create_team_name(server_t *server)
{
    if (server->game.team_count == 0) {
        printf("No team name set, default team names are "
            "Team1, Team2, Team3, Team4\n");
        strcpy(server->game.team_list[0].name, "Team1");
        server->game.team_list[0].remaining_spot = server->opt.client_nb;
        strcpy(server->game.team_list[1].name, "Team2");
        server->game.team_list[1].remaining_spot = server->opt.client_nb;
        strcpy(server->game.team_list[2].name, "Team3");
        server->game.team_list[2].remaining_spot = server->opt.client_nb;
        strcpy(server->game.team_list[3].name, "Team4");
        server->game.team_list[3].remaining_spot = server->opt.client_nb;
        server->game.team_count = 4;
    }
}

static void set_default_world_size(server_t *server)
{
    if (server->game.world.size_x == -1) {
        printf("No width set, default width is 10\n");
        server->game.world.size_x = 10;
    }
    if (server->game.world.size_y == -1) {
        printf("No height set, default height is 10\n");
        server->game.world.size_y = 10;
    }
}

static void fill_arg(server_t *server)
{
    set_default_world_size(server);
    if (server->opt.client_nb == -1) {
        printf("No client number set, default client number is 4\n");
        server->opt.client_nb = 4;
    }
    create_team_name(server);
    if (server->port == -1) {
        printf("No port set, default port is 4242\n");
        server->port = 4242;
    }
    if (server->opt.freq == -1) {
        printf("No frequency set, default frequency is 100 tps\n");
        server->opt.freq = 100;
    }
    for (int i = 0; i < server->game.team_count; ++i) {
        server->game.team_list[i].
        remaining_spot = server->opt.client_nb;
    }
}

static void check_server_arg(server_t *server)
{
    if ((server->opt.client_nb <= 0 || server->opt.client_nb > MAX_CLIENT_NB)
    && server->opt.client_nb != -1) {
        my_error("Error: Clients must be between 1 and 100", 84);
    }
    if ((server->opt.freq <= 0 || server->opt.freq > MAX_FREQUENCE_NB)
        && server->opt.freq != -1) {
        my_error("Error: Frequency cannot be greater than 150", 84);
    }
    if (server->game.team_count > MAX_TEAM_NB) {
        my_error("Error: You can't have more than 10 teams", 84);
    }
}

void check_arg_validity(server_t *server)
{
    if ((server->port <= 0 || server->port > MAX_PORT_NB) &&
    server->port != -1) {
        my_error("Error: Port must be between 1 and 65535", 84);
    }
    if ((server->game.world.size_x <= 0 ||
        server->game.world.size_x > MAX_WORLD_SIZE)
    && server->game.world.size_x != -1) {
        my_error("Error: Width must be between 1 and 100", 84);
    }
    if ((server->game.world.size_y <= 0 ||
        server->game.world.size_y > MAX_WORLD_SIZE)
    && server->game.world.size_y != -1) {
        my_error("Error: Height must be between 1 and 100", 84);
    }
    check_server_arg(server);
    fill_arg(server);
}
