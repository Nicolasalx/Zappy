/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** map_size_reply
*/

#include "PlayerParser.hpp"
#include <sstream>

void Gui::PlayerParser::mapSizeReply(std::string args)
{
    std::stringstream strstream(args);

    strstream >> this->_gameData->mapSize.x >> this->_gameData->mapSize.y;
}
