/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_server.h"

static void create_team_name(server_t *server)
{
    if (server->args.team_count == 0) {
        printf("No team name set, default team names are Team1, Team2, Team3, Team4\n");
        server->args.teams[0] = strdup("Team1");
        server->args.teams[1] = strdup("Team2");
        server->args.teams[2] = strdup("Team3");
        server->args.teams[3] = strdup("Team4");
        server->args.team_count = 4;
    }
}

static void fill_arg(server_t *server)
{
    if (server->args.width == -1 && server->args.height == -1) {
        printf("No map dimensions set, default is 10x10\n");
        server->args.width = 10;
        server->args.height = 10;
    }
    if (server->args.width == -1 || server->args.height == -1) {
        my_error("Error: Map dimensions are not set", 84);
    }
    create_team_name(server);
    if (server->args.port == -1) {
        printf("No port set, default port is 4242\n");
        server->args.port = 4242;
    }
    if (server->args.client_nb == -1) {
        printf("No client number set, default client number is 4\n");
        server->args.client_nb = 4;
    }
    if (server->args.freq == -1) {
        printf("No frequency set, default frequency is 100 tps\n");
        server->args.freq = 100;
    }
}

void check_arg_validity(server_t *server)
{
    if ((server->args.port < 0 || server->args.port > MAX_PORT_NB) && server->args.port != -1) {
        my_error("Error: Port must be between 1 and 65535", 84);
    }
    if (server->args.width <= 0 && server->args.width > 100 && server->args.width != -1) {
        my_error("Error: Width must be between 1 and 100", 84);
    }
    if (server->args.height <= 0 && server->args.height > 100 && server->args.height != -1) {
        my_error("Error: Height must be between 1 and 100", 84);
    }
    if (server->args.client_nb <= 0 && server->args.client_nb > 100 && server->args.client_nb != -1) {
        my_error("Error: Clients must be between 1 and 100", 84);
    }
    if (server->args.freq <= 0 && server->args.freq > 10000 && server->args.freq != -1) {
        my_error("Error: Frequency cannot be greater than 10000", 84);
    }
    fill_arg(server);
}