/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initPlayer
*/

#include "Player.hpp"

Gui::Player::Player(std::shared_ptr<GameData> GameData) : _gameData(std::move(GameData))
{
    this->playerOrientation[1] = 180;
    this->playerOrientation[2] = 90;
    this->playerOrientation[3] = 0;
    this->playerOrientation[4] = 270;
}
