/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** right_reply
*/

#include "PlayerParser.hpp"

void Gui::PlayerParser::rightReply(const std::string &args)
{
    if (args == "ok\n") {
        if (_gameData->playerList.empty())
            return;
        _gameData->playerList[0].orientation += 1;
        if (_gameData->playerList[0].orientation > 4)
            _gameData->playerList[0].orientation = 1;
    }
}
