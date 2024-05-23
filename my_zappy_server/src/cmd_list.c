/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** cmd_list
*/

#include "zappy_server.h"

const gui_handler_t gui_cmd_handler[] =
{
    {"msz", 0, msz_cmd}, // map size
    {"bct", 2, bct_cmd}, // content of a tile
    {"mct", 0, mct_cmd}, // content of the map (all the tiles)
    {"tna", 0, tna_cmd}, // name of all the teams
    {"ppo", 1, ppo_cmd}, // player’s position
    {"plv", 1, plv_cmd}, // player’s level
    {"pin", 1, pin_cmd}, // player’s inventory
    {"sgt", 0, sgt_cmd}, // time unit request
    {"sst", 1, sst_cmd}, // time unit modification
    {NULL, 0, NULL}
};

const ai_handler_t ai_cmd_handler[] =
{
    {"Forward\n", false, forward_cmd},
    {"Right\n", false, right_cmd},
    {"Left\n", false, left_cmd},
    {"Look\n", false, NULL},
    {"Inventory\n", false, inventory_cmd},
    {"Broadcast", true, NULL},
    {"Connect_nbr\n", false, connect_nbr_cmd},
    {"Fork\n", false, NULL},
    {"Eject\n", false, NULL},
    {"Take", true, take_object_cmd},
    {"Set", true, set_object_cmd},
    {"Incantation\n", false, NULL},
    {NULL, false, NULL}
};
