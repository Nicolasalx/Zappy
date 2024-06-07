/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct
*/

#include "Parser.hpp"

void Gui::Parser::bct(std::vector<std::string> args)
{
    if (args.size() != 9)
        return;
    if (_gameData->mapSize.x == 0 || _gameData->mapSize.y == 0)
        return;
    for (int i = 0; i < 7; i++) {
        _gameData->objectPos[std::stoi(args[1])][std::stoi(args[0])][i] = std::stoi(args[i + 2]);
    }
}
