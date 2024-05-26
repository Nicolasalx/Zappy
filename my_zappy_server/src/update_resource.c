/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** update_resource
*/

#include <sys/time.h>
#include "zappy_server.h"

void update_resource(server_t *server)
{
    struct timeval current_time = {0};
    double elapsed_time = 0;

    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec -
    server->last_resource_spawn.tv_sec) * 1000.0;
    elapsed_time += (current_time.tv_usec -
    server->last_resource_spawn.tv_usec) / 1000.0;
    if (elapsed_time >= (RESOURCE_RESPAWN_FREQ / server->freq) * 1000.0) {
        spawn_resource(server);
        gettimeofday(&server->last_resource_spawn, NULL);
    }
}
