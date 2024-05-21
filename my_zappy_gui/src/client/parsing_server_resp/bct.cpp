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
    pos_t pos;
    pos.x = std::stoi(args[0]);
    pos.y = std::stoi(args[1]);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < std::stoi(args[i + 2]); j++) {
            this->object_pos[i].push_back(pos);
        }
    }
    // std::cout << "bct" << std::endl;
    // for (auto arg : args) {
    //     std::cout << arg << std::endl;
    // }
}