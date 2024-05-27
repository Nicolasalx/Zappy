/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** connectPlayer
*/

#include "zappyAi.hpp"

void Ai::Player::setDataTeam(int nbSlots, int xAxis, int yAxis)
{
    _clientHasaTeam = true;
    this->_nbSlotsTeam = nbSlots;
    this->dimensionWorld.x = xAxis;
    this->dimensionWorld.y = yAxis;
}
