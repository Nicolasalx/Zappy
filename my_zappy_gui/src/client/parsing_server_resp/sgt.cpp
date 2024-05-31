/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** sgt
*/

#include "zappy_gui.hpp"

void Gui::GameState::sgt(std::vector<std::string> args)
{
    if (args.size() != 1)
        return;
    // std::cout << "sgt" << std::endl;
    // for (auto arg : args) {
    //     std::cout << arg << std::endl;
    // }
    time_unit = std::stoi(args[0]);
}
