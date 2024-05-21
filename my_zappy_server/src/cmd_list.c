/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** cmd_list
*/

#include "zappy_server.h"

const gui_handler_t gui_cmd_handler[] =
{
    {"msz", 0, NULL}, // map size
    {"bct", 2, NULL}, // content of a tile
    {"mct", 0, NULL}, // content of the map (all the tiles)
    {"tna", 0, NULL}, // name of all the teams
    {"ppo", 1, NULL}, // player’s position
    {"plv", 1, NULL}, // player’s level
    {"pin", 1, NULL}, // player’s inventory
    {"sgt", 0, NULL}, // time unit request
    {"sst", 1, NULL}, // time unit modification
    {NULL, 0, NULL}
};

const char *ai_cmd[] =
{
    "Forward",
    "Right",
    "Left",
    "Look",
    "Inventory",
    "Broadcast",
    "Connect_nbr",
    "Fork",
    "Eject",
    "Take",
    "Set",
    "Incantation"
};
