/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** monitor_client
*/

#include "zappy_server.h"
#include <sys/time.h>

static void compute_select_timeout(server_t *server)
{
    ssize_t computation_time = 0;

    computation_time = (server->time.end.tv_sec - server->time.start.tv_sec)
        * 1000000 + (server->time.end.tv_usec - server->time.start.tv_usec);
    server->time.timeout.tv_sec = 0;
    server->time.timeout.tv_usec = 1000000 /
        server->opt.freq - computation_time;
    if (server->time.timeout.tv_usec < 0) {
        server->time.timeout.tv_usec = 0;
    }
}

void monitor_client(server_t *server, int max_fd)
{
    int nb_fd = 0;

    gettimeofday(&server->time.end, NULL);
    compute_select_timeout(server);
    nb_fd = select(max_fd + 1, &server->read_set,
        &server->write_set, NULL, &server->time.timeout);
    if (nb_fd == -1) {
        dprintf(2, RED("Select fail\n"));
        delete_server(server);
        my_exit(84);
    }
    gettimeofday(&server->time.start, NULL);
}
