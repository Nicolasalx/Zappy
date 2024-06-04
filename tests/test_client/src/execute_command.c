/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** execute_command
*/

#include "test_client.h"

static void make_overflow(client_t *client)
{
    char *cmd = NULL;

    cmd = my_calloc(sizeof(char) * 1000000);
    for (size_t i = 0; i < 1000000 - 1; ++i) {
        cmd[i] = 'A';
    }
    for (size_t i = 0; i < 10; ++i) {
        send_cmd_to_server(client, cmd);
    }
    send_cmd_to_server(client, "\n");
    my_free(cmd);
}

static void make_in_overflow(client_t *client)
{
    char *cmd = NULL;

    cmd = my_calloc(sizeof(char) * 1000);
    for (size_t i = 0; i < 1000 - 1; ++i) {
        cmd[i] = 'A';
    }
    for (size_t i = 0; i < 1000; ++i) {
        send_cmd_to_server(client, cmd);
    }
    send_cmd_to_server(client, "\n");
    my_free(cmd);
}

void execute_command(client_t *client, char *command)
{
    command[strlen(command) - 1] = '\0';

    if (strcmp(command, "MAKE_OVERFLOW") == 0) {
        make_overflow(client);
        return;
    }
    if (strcmp(command, "MAKE_IN_OVERFLOW") == 0) {
        make_in_overflow(client);
        return;
    }
    for (size_t i = 0; command[i] != '\0'; ++i) {
        if (command[i] == '#') {
            command[i] = '\n';
        }
    }
    send_cmd_to_server(client, command);
}
