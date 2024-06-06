/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** strategy_handler
*/

#include "zappy_ai.h"

void (*const strategy_handler[NB_STRATEGY][10])(client_t *) =
{
    [NOT_SET] = {
        get_nb_food,
        determine_role,
        NULL
    },
    [FARMER] = {
        look_for_elem,
        take_elements_on_floor,
        move_next_case,
        start_backtrace,
        farmer_backtrace,
        farmer_drop_items,
        NULL
    },
    [QUEEN] = {
        queen_get_inventory,
        queen_eat,
        queen_check_nb_food,
        queen_create_child,
        queen_incantation,
        NULL
    },
    [DEAD_FORK] = {
        dead_fork,
        wait_end_fork,
        NULL
    },
    [KILL_IT_SELF] = {
        kill_it_self,
        NULL
    }
};
