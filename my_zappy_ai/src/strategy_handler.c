/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** strategy_handler
*/

#include "zappy_ai.h"

void (*strategy_handler[NB_STRATEGY][10])(client_t *) =
{
    [NOT_SET] = {
        queen_management,
        NULL
    },
    [FARMER] = {
        NULL
    },
    [QUEEN] = {
        queen_management,
        NULL
    },
    [DEAD_FORK] = {
        drop_food,
        NULL
    },
};
