/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** setNewMessage
*/

#include "zappyAi.hpp"
#include "message.hpp"

void Ai::Player::setNewMessage(const Message &message)
{
    this->_listMessage.push_back(message);
}
