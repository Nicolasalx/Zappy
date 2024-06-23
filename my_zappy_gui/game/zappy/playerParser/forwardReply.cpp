/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** forward_reply
*/

#include "PlayerParser.hpp"

void Gui::PlayerParser::forwardReply(const std::string &args)
{
    if (args == "ok\n") {
        std::cout << "ANIMATION FORWARD\n";
        if (_gameData->playerList.empty())
            return;
        if (_gameData->playerList[0].orientation == 0)
            _gameData->playerList[0].pos.x -= 1;
        if (_gameData->playerList[0].orientation == 1)
            _gameData->playerList[0].pos.y += 1;
        if (_gameData->playerList[0].orientation == 2)
            _gameData->playerList[0].pos.x += 1;
        if (_gameData->playerList[0].orientation == 3)
            _gameData->playerList[0].pos.y -= 1;
    }
}
