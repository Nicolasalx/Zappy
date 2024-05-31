/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pie
*/

#include "zappy_gui.hpp"

void GameState::pie(std::vector<std::string> args)
{
    if (args.size() < 3)
        return;
    for (size_t i = 0; i < incant_list.size(); i++) {
        if (incant_list[i].pos.x == std::stoi(args[0]) && incant_list[i].pos.y == std::stoi(args[1])) {
            incant_list.erase(incant_list.begin() + i);
            return;
        }
    }
}