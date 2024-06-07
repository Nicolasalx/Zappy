/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct
*/

#include "Parser.hpp"

void Gui::Parser::edi(std::vector<std::string> args)
{
    int egg_number = std::stoi(args[0]);
    for (auto it = _gameData->eggList.begin(); it != _gameData->eggList.end(); it++) {
        if (it->egg_number == egg_number) {
            _gameData->eggList.erase(it);
            break;
        }
    }
}
