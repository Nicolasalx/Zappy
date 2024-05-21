/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** msz
*/

#include "zappy_gui.hpp"

void GameState::msz(std::vector<std::string> args)
{
    if (args.size() != 2)
        return;
    std::cout << "msz" << std::endl;
    for (auto arg : args) {
        std::cout << arg << std::endl;
    }
    width = std::stoi(args[0]);
    height = std::stoi(args[1]);
}
