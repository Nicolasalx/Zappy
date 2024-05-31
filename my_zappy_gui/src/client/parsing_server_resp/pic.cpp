/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pic
*/

#include "gameState.hpp"

static bool check_if_already_exist(std::vector<Gui::incant_t> incant_list, Gui::incant_t incant)
{
    for (size_t i = 0; i < incant_list.size(); i++) {
        if (incant_list[i].pos.x == incant.pos.x && incant_list[i].pos.y == incant.pos.y) {
            return true;
        }
    }
    return false;
}

void Gui::GameState::pic(std::vector<std::string> args)
{
    if (args.size() < 3)
        return;
    incant_t incant;
    incant.pos.x = std::stoi(args[0]);
    incant.pos.y = std::stoi(args[1]);
    incant.level = std::stoi(args[2]);
    if (check_if_already_exist(this->incant_list, incant))
        return;
    this->incant_list.push_back(incant);
}