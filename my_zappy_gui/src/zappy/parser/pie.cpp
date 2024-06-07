/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pie
*/

#include "Parser.hpp"

void Gui::Parser::pie(std::vector<std::string> args)
{
    if (args.size() < 3)
        return;
    for (size_t i = 0; i < _gameData->incantList.size(); i++) {
        if (_gameData->incantList[i].pos.x == std::stoi(args[0]) && _gameData->incantList[i].pos.y == std::stoi(args[1])) {
            _gameData->incantList.erase(_gameData->incantList.begin() + i);
            return;
        }
    }
}
