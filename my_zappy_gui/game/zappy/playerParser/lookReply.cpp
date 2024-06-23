/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look_reply
*/

#include "PlayerParser.hpp"
#include "split_string.hpp"

void Gui::PlayerParser::lookReply(const std::string &args)
{
    std::vector<std::string> tile;
    std::vector<std::string> tileContent;
    std::array<std::array<int, 8>, 81> res;
    std::array<std::string, 8> resStr = {"player", "food",
        "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"};

    my::split_string(args, ",", tile);
    for (std::size_t i = 0; i < tile.size(); ++i) {
        my::split_string(tile[i], " ", tileContent);
        for (const std::string &ressource : tileContent) {
            for (std::size_t j = 0; j < resStr.size(); ++j) {
                if (ressource == resStr[j]) {
                    ++res[i][j];
                }
            }
        }
    }
    for (std::size_t i = 0; i < res.size(); ++i) {
        for (std::size_t j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // update the ressource on tile with "res" array
    for (std::size_t i = 0; i < _gameData->objectPos.size(); ++i) {
        for (std::size_t j = 0; j < _gameData->objectPos[i].size(); ++j) {
            for (std::size_t k = 0; k < _gameData->objectPos[i][j].size(); ++k) {
                _gameData->objectPos[i][j][k] = 0;
            }
        }
    }

    for (std::size_t j = 0; j < res[0].size(); ++j) {
        _gameData->objectPos[_gameData->playerList[0].pos.y][_gameData->playerList[0].pos.x][j] = res[0][j - 1];
    }

    if (_gameData->playerList[0].pos.x == 0 || _gameData->playerList[0].pos.y == 0 || _gameData->playerList[0].pos.x == _gameData->mapSize.x - 1 || _gameData->playerList[0].pos.y == _gameData->mapSize.y - 1)
        return;

    for (std::size_t j = 0; j < res[1].size(); ++j) {
        if (_gameData->playerList[0].orientation == 1)
            _gameData->objectPos[_gameData->playerList[0].pos.y - 1][_gameData->playerList[0].pos.x - 1][j] = res[1][j + 1];
        if (_gameData->playerList[0].orientation == 2)
            _gameData->objectPos[_gameData->playerList[0].pos.y - 1][_gameData->playerList[0].pos.x + 1][j] = res[1][j + 1];
        if (_gameData->playerList[0].orientation == 3)
            _gameData->objectPos[_gameData->playerList[0].pos.y + 1][_gameData->playerList[0].pos.x + 1][j] = res[1][j + 1];
        if (_gameData->playerList[0].orientation == 4)
            _gameData->objectPos[_gameData->playerList[0].pos.y + 1][_gameData->playerList[0].pos.x - 1][j] = res[1][j + 1];
    }
    for (std::size_t j = 0; j < res[2].size(); ++j) {
        if (_gameData->playerList[0].orientation == 1)
            _gameData->objectPos[_gameData->playerList[0].pos.y - 1][_gameData->playerList[0].pos.x][j] = res[2][j + 1];
        if (_gameData->playerList[0].orientation == 2)
            _gameData->objectPos[_gameData->playerList[0].pos.y][_gameData->playerList[0].pos.x + 1][j] = res[2][j + 1];
        if (_gameData->playerList[0].orientation == 3)
            _gameData->objectPos[_gameData->playerList[0].pos.y + 1][_gameData->playerList[0].pos.x][j] = res[2][j + 1];
        if (_gameData->playerList[0].orientation == 4)
            _gameData->objectPos[_gameData->playerList[0].pos.y][_gameData->playerList[0].pos.x - 1][j] = res[2][j + 1];
    }
    for (std::size_t j = 0; j < res[3].size(); ++j) {
        if (_gameData->playerList[0].orientation == 1)
            _gameData->objectPos[_gameData->playerList[0].pos.y - 1][_gameData->playerList[0].pos.x - 1][j] = res[3][j + 1];
        if (_gameData->playerList[0].orientation == 2)
            _gameData->objectPos[_gameData->playerList[0].pos.y - 1][_gameData->playerList[0].pos.x + 1][j] = res[3][j + 1];
        if (_gameData->playerList[0].orientation == 3)
            _gameData->objectPos[_gameData->playerList[0].pos.y + 1][_gameData->playerList[0].pos.x + 1][j] = res[3][j + 1];
        if (_gameData->playerList[0].orientation == 4)
            _gameData->objectPos[_gameData->playerList[0].pos.y + 1][_gameData->playerList[0].pos.x - 1][j] = res[3][j + 1];
    }
}
