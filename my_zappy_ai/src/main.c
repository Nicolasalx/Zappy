/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_ai.h"
#include <sys/wait.h>

node_t *child_list = {NULL};

void create_new_ai(int port, struct in_addr *address, char *team_name)
{
    pid_t pid = fork();

    if (pid == -1) {
        dprintf(2, RED("Failed to fork a new ai.\n"));
    } else if (pid == 0) {
        client_t client = {0};

        client.port = port;
        client.server_address.sin_addr = *address;
        strcpy(client.team_name, team_name);
        //check_arg_validity(argc, argv, &client);
        create_client(&client);
        lauch_client(&client);
        delete_client(&client);
        free_all_alloc();
        my_exit(0);
    }
    pid_t **child_pid = my_calloc(sizeof(pid_t *));

    *child_pid = &pid;
    append_node(&child_list, create_node(child_pid));
}

int main(int argc, char const *argv[])
{
    client_t client = {0};

    strcpy(client.team_name, "Team1");
    check_arg_validity(argc, argv, &client);
    create_client(&client);
    lauch_client(&client);
    delete_client(&client);
    node_t *current = child_list;
    int status = 0;

    if (child_list) {
        do {
            waitpid(*GET_DATA(current, pid_t), &status, 0);
            current = current->next;
        } while (current != child_list);
    }
    free_all_alloc();
    return 0;
}
