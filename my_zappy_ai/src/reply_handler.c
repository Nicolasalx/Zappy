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
    {FORWARD, NULL},
    {RIGHT, NULL},
    {LEFT, NULL},
    {LOOK, look_command_reply},
    {INVENTORY, inventory_command_reply},
    {BROADCAST, NULL},
    {CONNECT_NBR, connect_nbr_command_reply},
    {FORK, fork_command_reply},
    {EJECT, NULL},
    {TAKE, take_command_reply},
    {SET, set_command_reply},
    {INCANTATION, incantation_command_reply},
    {0, NULL}
};
