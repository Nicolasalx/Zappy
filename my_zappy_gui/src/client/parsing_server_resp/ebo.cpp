/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct
*/

#include "zappy_gui.hpp"

void Gui::GameState::ebo(std::vector<std::string> args)
{
    int egg_number = std::stoi(args[0]);
    for (auto it = eggs_list.begin(); it != eggs_list.end(); it++) {
        if (it->egg_number == egg_number) {
            eggs_list.erase(it);
            break;
        }
    }
}
