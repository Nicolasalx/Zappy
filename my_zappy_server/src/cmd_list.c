/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** cmd_list
*/

#include "zappy_server.h"

const char **gui_cmd =
{
    "msz", // map size
    "bct", // content of a tile
    "mct", // content of the map (all the tiles)
    "tna", // name of all the teams
    "ppo", // player’s position
    "plv", // player’s level
    "pin", // player’s inventory
    "sgt", // time unit request
    "sst"  // time unit modification
};

const char **ai_cmd =
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
