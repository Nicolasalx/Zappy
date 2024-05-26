/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_server.h"

static void create_team_name(server_t *server)
{
    if (server->team_count == 0) {
        printf("No team name set, default team names are "
            "Team1, Team2, Team3, Team4\n");
        strcpy(server->team_list[0].name, "Team1");
        server->team_list[0].remaining_place = server->client_nb;
        strcpy(server->team_list[1].name, "Team2");
        server->team_list[1].remaining_place = server->client_nb;
        strcpy(server->team_list[2].name, "Team3");
        server->team_list[2].remaining_place = server->client_nb;
        strcpy(server->team_list[3].name, "Team4");
        server->team_list[3].remaining_place = server->client_nb;
        server->team_count = 4;
    }
}

static void fill_arg(server_t *server)
{
    if (server->world.size_x == -1 && server->world.size_y == -1) {
        printf("No map dimensions set, default is 10x10\n");
        server->world.size_x = 10;
        server->world.size_y = 10;
    }
    if (server->world.size_x == -1 || server->world.size_y == -1)
        my_error("Error: Map dimensions are not set", 84);
    if (server->client_nb == -1) {
        printf("No client number set, default client number is 4\n");
        server->client_nb = 4;
    }
    create_team_name(server);
    if (server->port == -1) {
        printf("No port set, default port is 4242\n");
        server->port = 4242;
    }
    if (server->freq == -1) {
        printf("No frequency set, default frequency is 100 tps\n");
        server->freq = 100;
    }
}

void check_arg_validity(server_t *server)
{
    if ((server->port < 0 || server->port > MAX_PORT_NB) &&
    server->port != -1) {
        my_error("Error: Port must be between 1 and 65535", 84);
    }
    if (server->world.size_x <= 0 && server->world.size_y > 100) {
        my_error("Error: Width must be between 1 and 100", 84);
    }
    if (server->world.size_x <= 0 && server->world.size_y > 100) {
        my_error("Error: Height must be between 1 and 100", 84);
    }
    if (server->client_nb <= 0 && server->client_nb > 100) {
        my_error("Error: Clients must be between 1 and 100", 84);
    }
    if (server->freq <= 0 && server->freq > 10000) {
        my_error("Error: Frequency cannot be greater than 10000", 84);
    }
    fill_arg(server);
}
