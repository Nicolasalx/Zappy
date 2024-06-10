/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct
*/

#include "zappy_gui.hpp"

void Gui::GameState::enw(std::vector<std::string> args)
{
    egg_t egg;
    egg.egg_number = std::stoi(args[0]);
    egg.player_number = std::stoi(args[1]);
    egg.pos.x = std::stoi(args[2]);
    egg.pos.y = std::stoi(args[3]);
    for (auto it = eggs_list.begin(); it != eggs_list.end(); it++) {
        if (it->pos.x == egg.pos.x && it->pos.y == egg.pos.y) {
            return;
        }
    }
    eggs_list.push_back(egg);
}
