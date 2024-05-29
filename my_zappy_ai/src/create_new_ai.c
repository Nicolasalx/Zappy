/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_new_ai
*/

#include "zappy_ai.h"
#include <sys/wait.h>

node_t *child_list = {NULL};

void create_new_ai(int port, struct in_addr *address, char *team_name)
{
    pid_t **child_pid = my_calloc(sizeof(pid_t *));
    pid_t pid = fork();

    if (pid == -1) {
        dprintf(2, RED("Failed to fork a new ai.\n"));
    } else if (pid == 0) {
        client_t client = {0};

        srand(time(NULL) + getpid());
        client.port = port;
        client.server_address.sin_addr = *address;
        strcpy(client.player.team_name, team_name);
        create_client(&client);
        launch_client(&client);
        delete_client(&client);
        free_all_alloc();
        my_exit(0);
    }
    *child_pid = &pid;
    append_node(&child_list, create_node(child_pid));
}

void wait_for_child(void)
{
    node_t *current = child_list;
    int status = 0;

    if (child_list) {
        do {
            waitpid(*GET_DATA(current, pid_t), &status, 0);
            current = current->next;
        } while (current != child_list);
    }
}
