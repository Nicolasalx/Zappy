/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** execute_command
*/

#include "test_client.h"

void execute_command(client_t *client, char *command)
{
    command[strlen(command) - 1] = '\0';
    for (size_t i = 0; command[i] != '\0'; ++i) {
        if (command[i] == '#') {
            command[i] = '\n';
        }
    }
    send_cmd_to_server(client, command);
}
