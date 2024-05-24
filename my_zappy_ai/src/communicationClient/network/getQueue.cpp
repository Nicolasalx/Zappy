/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** getQueue
*/

#include "zappyAi.hpp"

void Ai::Client::setQueue(const std::list<Ai::CommandType> &queue)
{
    this->_queueCommand = queue;
}


std::list<Ai::CommandType> Ai::Client::getQueue()
{
    return _queueCommand;
}
