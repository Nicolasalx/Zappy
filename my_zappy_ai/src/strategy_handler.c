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
        NULL
    },
    [FARMER] = {
        NULL
    },
    [QUEEN] = {
        NULL
    },
    [DEAD_FORK] = {
        NULL
    },
};
