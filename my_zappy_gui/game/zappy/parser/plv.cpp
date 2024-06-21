/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** plv
*/

#include "Parser.hpp"

void Gui::Parser::plv(std::vector<std::string> args)
{
    if (args.size() != 2)
        return;
    int player_id = std::stoi(args[0]);
    for (auto &it : _gameData->playerList) {
        if (it.n == player_id) {
            it.level = std::stoi(args[1]);
            break;
        }
    }
}
