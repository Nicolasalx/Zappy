/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct
*/

#include "Parser.hpp"

void Gui::Parser::enw(std::vector<std::string> args)
{
    EggData egg;
    egg.egg_number = std::stoi(args[0]);
    egg.player_number = std::stoi(args[1]);
    egg.pos.x = std::stoi(args[2]);
    egg.pos.y = std::stoi(args[3]);
    for (auto it = _gameData->eggList.begin(); it != _gameData->eggList.end(); it++) {
        if (it->pos.x == egg.pos.x && it->pos.y == egg.pos.y) {
            return;
        }
    }
    _gameData->eggList.push_back(egg);
}
