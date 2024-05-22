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
        if (!server->is_immortal) {
            for (int i = 0; i < MAX_CLIENT; ++i) {
                if (server->clients[i].fd == 0
                || server->clients[i].is_graphic
                || !server->clients[i].player.team) {
                    continue;
                }
                server->clients[i].player.food_time_unit += 1;
                printf("Decrease food unit\n");
                if (server->clients[i].player.food_time_unit > 126) {
                    server->clients[i].player.food_time_unit = 0;
                    server->clients[i].player.inventory[FOOD] -= 1;
                    printf("Decrease food %d\n", server->clients[i].player.inventory[FOOD]);
                    if (server->clients[i].player.inventory[FOOD] <= 0) {
                        send_msg_client(server->clients[i].fd, "dead\n");
                        remove_client(&server->clients[i]);
                    }
                }
            }
        }
        gettimeofday(&server->last_update, NULL);
    }
}
