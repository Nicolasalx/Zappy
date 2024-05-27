/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** setTileToMap
*/

#include "zappyAi.hpp"

void Ai::Player::setMap(std::vector<Tile> listTile)
{
    this->_contentLook = listTile;
}
