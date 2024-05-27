/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** reply_handler
*/

#include "zappy_ai.h"

const reply_handler_t reply_handler[] =
{
    {NONE, first_action},
    {FORWARD, forward_command},
    {RIGHT, right_command},
    {LEFT, left_command},
    {LOOK, look_command},
    {INVENTORY, inventory_command},
    {BROADCAST, broadcast_command},
    {CONNECT_NBR, connect_nbr_command},
    {FORK, fork_command},
    {EJECT, eject_command},
    {TAKE, take_command},
    {SET, set_command},
    {INCANTATION, incantation_command},
    {0, NULL}
};
