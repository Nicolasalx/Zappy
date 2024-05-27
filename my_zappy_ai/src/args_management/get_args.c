/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_ai.h"

static void get_port(const char **argv, client_t *client, int i, const char **args)
{
    if (strcmp(argv[i], args[0]) == 0) {
        if (argv[i + 1] == NULL) {
            printf("Error: Port must be specified\n");
            my_exit(84);
        }
        if (!my_str_only_cont(argv[i + 1], "0123456789")) {
            printf("Error: Port must be a number\n");
            my_exit(84);
        }
        client->port = atoi(argv[i + 1]);
    }
}

static void get_ip(const char **argv, client_t *client, int i, const char **args)
{
    if (strcmp(argv[i], args[1]) == 0) {
        if (argv[i + 1] == NULL) {
            printf("Error: Machine must be specified\n");
            my_exit(84);
        }
        if (strcmp(argv[i + 1], "localhost") && inet_aton(argv[i + 1], &client->server_address.sin_addr) == 0) {
            printf("Error: Invalid IP address\n");
            my_exit(84);
        }
    }
}

static void get_team_name(const char **argv, client_t *client, int i, const char **args)
{
    if (strcmp(argv[i], args[2]) == 0) {
        if (argv[i + 1] == NULL) {
            printf("Error: Team must be specified\n");
            my_exit(84);
        }
        if (strlen(argv[i + 1]) > MAX_TEAMNAME_SIZE) {
            printf("Error: Team name is too long\n");
            my_exit(84);
        }
        strcpy(client->player.team_name, argv[i + 1]);
    }
}

static void set_args(client_t *client)
{
    client->port = -1;
    client->player.team_name[0] = '\0';
}


void fill_args(client_t *client)
{
    if (client->port == -1)
        client->port = 4242;
    if (client->player.team_name[0] == '\0')
        strcpy(client->player.team_name, "Team1");
}

void get_args(int argc, const char **argv, client_t *client)
{
    const char *args[] = {"-p", "-h", "-n"};
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./zappy_ai -p port -n name -h machine\n");
        my_exit(0);
    }
    set_args(client);
    for (int i = 1; i < argc; i++) {
        get_port(argv, client, i, args);
        get_ip(argv, client, i, args);
        get_team_name(argv, client, i, args);
    }
    fill_args(client);
}
