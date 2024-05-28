/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** push_new_command
*/

#include "zappy_ai.h"

void push_new_command(client_t *client, cmd_list_t cmd_type, char *cmd)
{
    cmd_to_make_t *cmd_to_make = my_calloc(sizeof(cmd_to_make_t));

    cmd_to_make->cmd_type = cmd_type;
    if (cmd) {
        cmd_to_make->arg = my_strdup(cmd);
        printf(RED("pushed cmd:")" %s\n", cmd);
    }
    append_node(&client->cmd_to_make, create_node(cmd_to_make));
}

void pop_cmd_to_make(client_t *client)
{
    if (!client->cmd_to_make) {
        if (strategy_handler[client->strategy][client->instruction_index]) {
            strategy_handler[client->strategy][client->instruction_index](client);
            ++client->instruction_index;
        }
        if (strategy_handler[client->strategy][client->instruction_index] == NULL) {
            client->instruction_index = 0;
        }
    }
    if (!client->cmd_to_make) {
        return;
    }
    client->last_cmd = GET_DATA(client->cmd_to_make, cmd_to_make_t)->cmd_type;
    send_cmd_to_server(client, GET_DATA(client->cmd_to_make, cmd_to_make_t)->arg);
    delete_node(&client->cmd_to_make, client->cmd_to_make);
}
