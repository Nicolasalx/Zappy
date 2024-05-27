/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** reply_handler
*/

#include "zappy_ai.h"

const reply_handler_t reply_handler[] =
{
    {NONE, first_action_reply},
    {FORWARD, forward_command_reply},
    {RIGHT, right_command_reply},
    {LEFT, left_command_reply},
    {LOOK, look_command_reply},
    {INVENTORY, inventory_command_reply},
    {BROADCAST, broadcast_command_reply},
    {CONNECT_NBR, connect_nbr_command_reply},
    {FORK, fork_command_reply},
    {EJECT, eject_command_reply},
    {TAKE, take_command_reply},
    {SET, set_command_reply},
    {INCANTATION, incantation_command_reply},
    {0, NULL}
};
