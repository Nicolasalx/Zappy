/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** strategy_handler
*/

#include "zappy_ai.h"

void my_forward_func(client_t *client)
{
    push_new_command(client, FORWARD, "Forward\n");
    push_new_command(client, FORWARD, "Forward\n");
    push_new_command(client, FORWARD, "Forward\n");
}

void my_right_func(client_t *client)
{
    push_new_command(client, RIGHT, "Right\n");
}

void (*strategy_handler[NB_STRATEGY][10])(client_t *) =
{
    [NOT_SET] =
    {
        my_forward_func,
        my_right_func,
        NULL
    },
    [FARMER] = {NULL},
    [QUEEN] = {NULL},
    [DEAD_FORK] = {NULL},
};
