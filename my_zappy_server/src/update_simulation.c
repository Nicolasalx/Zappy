/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** update_simulation
*/

#include <sys/time.h>
#include "zappy_server.h"

static void ai_command_wait_list(server_t *server, int i)
{
    if (GET_DATA(server->clients[i].waiting_cmd,
        waiting_cmd_t)->time_to_wait <= 0) {
            GET_DATA(server->clients[i].waiting_cmd,
            waiting_cmd_t)->method(
                GET_DATA(server->clients[i].waiting_cmd,
                waiting_cmd_t)->args, &server->clients[i], server);
            my_free(GET_DATA(server->clients[i].waiting_cmd,
            waiting_cmd_t)->args);
            delete_node(&server->clients[i].waiting_cmd,
            server->clients[i].waiting_cmd);
        }
}

void execute_ai_command(server_t *server)
{
    for (size_t i = 0; i < MAX_CLIENT; ++i) {
        if (server->clients[i].fd
        && server->clients[i].waiting_cmd &&
        !server->clients[i].in_incentation) {
            --GET_DATA(server->clients[i].waiting_cmd,
            waiting_cmd_t)->time_to_wait;
            ai_command_wait_list(server, i);
        }
    }
}

void update_simulation(server_t *server)
{
    struct timeval current_time = {0};
    double elapsed_time = 0;

    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec -
    server->last_update.tv_sec) * 1000.0;
    elapsed_time += (current_time.tv_usec -
    server->last_update.tv_usec) / 1000.0;
    if (elapsed_time >= (1 / server->freq) * 1000.0) {
        execute_ai_command(server);
        consume_food(server);
        gettimeofday(&server->last_update, NULL);
    }
}
