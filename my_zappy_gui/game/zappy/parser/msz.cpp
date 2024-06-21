/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** msz
*/

#include "Parser.hpp"

void Gui::Parser::msz(std::vector<std::string> args)
{
    std::cout << "map size" << std::endl;
    std::cout << std::stoi(args[0]) << std::endl;
    std::cout << std::stoi(args[1]) << std::endl;
    if (args.size() != 2)
        return;

    _gameData->mapSize.x = std::stoi(args[0]);
    _gameData->mapSize.y = std::stoi(args[1]);
    std::vector<int> tmp;
    tmp.reserve(7);
    for (int i = 0; i < 7; i++) {
        tmp.push_back(0);
    }
    std::vector<std::vector<int>> tmp2;
    tmp2.reserve(_gameData->mapSize.x);
    for (int i = 0; i < _gameData->mapSize.x; i++) {
        tmp2.push_back(tmp);
    }
    for (int i = 0; i < _gameData->mapSize.y; i++) {
        _gameData->objectPos.push_back(tmp2);
    }
    for (int i = 0; i < _gameData->mapSize.x; i++) {
        for (int j = 0; j < _gameData->mapSize.y; j++) {
            _gameData->islandInfo.push_back(Pos{float(i), float(j)});
        }
    }
}
