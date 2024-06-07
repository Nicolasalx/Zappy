/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pdi
*/

#include "Parser.hpp"

void Gui::Parser::pdi(std::vector<std::string> args)
{
    if (args.size() != 1)
        return;
    int playerId = std::stoi(args[0]);
    for (auto it = _gameData->playerList.begin(); it != _gameData->playerList.end(); it++) {
        if (it->n == playerId) {
            _gameData->playerList.erase(it);
            break;
        }
    }
}
