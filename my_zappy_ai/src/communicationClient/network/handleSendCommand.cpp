/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseInventory
*/

#include "zappyAi.hpp"

bool Ai::Client::canSendCommand()
{
    return this->_cmdCanBeSend;
}

void Ai::Client::enableSendCommand()
{
    this->_cmdCanBeSend = true;
}

void Ai::Client::disableSendCommand()
{
    this->_cmdCanBeSend = false;
}
