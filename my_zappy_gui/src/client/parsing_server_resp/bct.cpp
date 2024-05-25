/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct
*/

#include "zappy_gui.hpp"

void GameState::bct(std::vector<std::string> args)
{
    if (args.size() != 9)
        return;
    if (map_size.x == 0 || map_size.y == 0)
        return;
    for (int i = 0; i < 7; i++) {
        object_pos[std::stoi(args[1])][std::stoi(args[0])][i] = std::stoi(args[i + 2]);
    }
}