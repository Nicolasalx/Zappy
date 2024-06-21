/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pic
*/

#include "Parser.hpp"

static bool check_if_already_exist(std::vector<Gui::Incant> incant_list, Gui::Incant incant)
{
    for (auto &i : incant_list) {
        if (i.pos.x == incant.pos.x && i.pos.y == incant.pos.y) {
            return true;
        }
    }
    return false;
}

void Gui::Parser::pic(std::vector<std::string> args)
{
    Incant incant;

    if (args.size() < 3)
        return;
    incant.pos.x = std::stoi(args[0]);
    incant.pos.y = std::stoi(args[1]);
    incant.level = std::stoi(args[2]);
    if (check_if_already_exist(_gameData->incantList, incant))
        return;
    _gameData->incantList.push_back(incant);
}