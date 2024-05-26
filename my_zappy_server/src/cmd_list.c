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
    {"Forward\n", false, 7, forward_cmd},
    {"Right\n", false, 7, right_cmd},
    {"Left\n", false, 7, left_cmd},
    {"Look\n", false, 7, look_cmd},
    {"Inventory\n", false, 1, inventory_cmd},
    {"Broadcast", true, 7, broadcast_cmd},
    {"Connect_nbr\n", false, 0, connect_nbr_cmd},
    {"Fork\n", false, 42, fork_cmd},
    {"Eject\n", false, 7, eject_cmd},
    {"Take", true, 7, take_object_cmd},
    {"Set", true, 7, set_object_cmd},
    {"Incantation\n", false, 300, incatation_cmd},
    {NULL, false, 0, NULL}
};

const server_handler_t server_cmd_handler[] =
{
    {"tp", 4, tp_cmd, "tp [n player] [x] [y] [orientation]"},
    {"level", 2, level_cmd, "level [n player] [k level]"},
    {"give", 3, give_cmd, "give [n player] [resource] [quantity]"},
    {"pause", 0, pause_cmd, "pause"},
    {"resume", 0, resume_cmd, "resume"},
    {NULL, 0, NULL, NULL}
};
