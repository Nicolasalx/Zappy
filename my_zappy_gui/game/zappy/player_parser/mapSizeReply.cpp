/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** map_size_reply
*/

#include "PlayerParser.hpp"
#include <sstream>

void Gui::PlayerParser::mapSizeReply(const std::string &args)
{
    std::stringstream strstream(args);

    strstream >> this->_gameData->mapSize.x >> this->_gameData->mapSize.y;

    if (this->_gameData->mapSize.x == 0 || this->_gameData->mapSize.y == 0 || !_gameData->playerList.empty()) {
        return;
    }

    PlayerData newPlayer;
    newPlayer.n = 0;
    newPlayer.pos.x = this->_gameData->mapSize.x / 2;
    newPlayer.pos.y = this->_gameData->mapSize.y / 2;
    newPlayer.real_pos.x = this->_gameData->mapSize.x / 2;
    newPlayer.real_pos.y = this->_gameData->mapSize.y / 2;
    newPlayer.orientation = rand() % 3 + 1;
    newPlayer.real_orientation = newPlayer.orientation;
    newPlayer.level = 1;
    newPlayer.team_name = "Team1";
    newPlayer.animation_nbr = 0;
    newPlayer.anim_frame_counter = 32;
    for (int i = 0; i < 7; i++) {
        newPlayer.inventory.push_back(0);
    }
    this->_gameData->playerList.push_back(newPlayer);

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
}
