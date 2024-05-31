/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** msz
*/

#include "zappy_gui.hpp"

void Gui::GameState::msz(std::vector<std::string> args)
{
    if (args.size() != 2)
        return;
    // std::cout << "msz" << std::endl;
    // for (auto arg : args) {
    //     std::cout << arg << std::endl;
    // }
    map_size.x = std::stoi(args[0]);
    map_size.y = std::stoi(args[1]);
    std::vector<int> tmp;
    for (int i = 0; i < 7; i++) {
        tmp.push_back(0);
    }
    std::vector<std::vector<int>> tmp2;
    for (int i = 0; i < map_size.x; i++) {
        tmp2.push_back(tmp);
    }
    for (int i = 0; i < map_size.y; i++) {
        object_pos.push_back(tmp2);
    }
}
