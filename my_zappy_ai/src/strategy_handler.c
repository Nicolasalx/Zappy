/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** strategy_handler
*/

#include "zappy_ai.h"

void get_nb_food(client_t *client)
{
    push_new_command(client, LOOK, "Look\n");
}

void determine_role(client_t *client)
{
    client->instruction_index = 0;
    if (client->player.content_look[0][TILE_FOOD] < 50) {
        client->strategy = DEAD_FORK;
        push_new_command(client, LOOK, "Connect_nbr\n");
        return;
    }
    if (rand() % 10 >= 7) {
        client->strategy = QUEEN;
    } else {
        client->strategy = FARMER;
    }
    push_new_command(client, CONNECT_NBR, "Connect_nbr\n");
}

// queen
// dead fork
// ! fork
// ! create new ai
// ! drop

void (*strategy_handler[NB_STRATEGY][10])(client_t *) =
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
};
