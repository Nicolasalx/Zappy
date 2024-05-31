/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pic
*/

#include "zappy_gui.hpp"

void Gui::GameState::pic(std::vector<std::string> args)
{
    if (args.size() < 3)
        return;
    incant_t incant;
    incant.pos.x = std::stoi(args[0]);
    incant.pos.y = std::stoi(args[1]);
    incant.level = std::stoi(args[2]);
    this->incant_list.push_back(incant);
}