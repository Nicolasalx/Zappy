/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_ai.h"

static void get_port(const char **argv, ai_arg_t *ai_arg, int i)
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
        ai_arg->port = atoi(argv[i + 1]);
    }
}

static void get_ip(const char **argv, ai_arg_t *ai_arg, int i)
{
    if (strcmp(argv[i], args[1]) == 0) {
        if (argv[i + 1] == NULL) {
            printf("Error: Machine must be specified\n");
            my_exit(84);
        }
        if (strcmp(argv[i + 1], "localhost")
        && inet_aton(argv[i + 1], &ai_arg->address) == 0) {
            printf("Error: Invalid IP address\n");
            my_exit(84);
        }
    }
}

static void get_team_name(const char **argv, ai_arg_t *ai_arg, int i)
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
        strcpy(ai_arg->team_name, argv[i + 1]);
    }
}

static void set_args(ai_arg_t *ai_arg)
{
    ai_arg->port = -1;
    ai_arg->team_name[0] = '\0';
}

static void fill_args(ai_arg_t *ai_arg)
{
    if (ai_arg->port == -1)
        ai_arg->port = 4242;
    if (ai_arg->team_name[0] == '\0')
        strcpy(ai_arg->team_name, "Team1");
}

static bool is_valid_argument(const char *arg)
{
    for (int i = 0; i < 5; ++i) {
        if (strcmp(arg, args[i]) == 0) {
            return true;
        }
    }
    return false;
}

void get_args(int argc, const char **argv, ai_arg_t *ai_arg)
{
    if (argc == 2 && strcmp(argv[1], "-help") == 0) {
        printf("USAGE: ./zappy_ai -p port -n name -h machine\n");
        my_exit(0);
    }
    set_args(ai_arg);
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && is_valid_argument(argv[i])) {
            get_port(argv, ai_arg, i);
            get_ip(argv, ai_arg, i);
            get_team_name(argv, ai_arg, i);
            i += 1;
        } else {
            my_error("Error: Invalid argument", 84);
        }
    }
    fill_args(ai_arg);
}
