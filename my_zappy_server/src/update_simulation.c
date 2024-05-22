/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** update_simulation
*/

#include <sys/time.h>
#include "zappy_server.h"

void update_simulation(server_t *server)
{
    struct timeval current_time = {0};
    double elapsed_time = 0;

    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec - server->last_update.tv_sec) * 1000.0;
    elapsed_time += (current_time.tv_usec - server->last_update.tv_usec) / 1000.0;
    if (elapsed_time >= (1 / server->freq) * 1000.0) {
        // printf("Compute\n");
        gettimeofday(&server->last_update, NULL);
    }
}
