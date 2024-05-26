/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** insertInQueue
*/

#include "client.hpp"

void Ai::Client::insertInQueue(CommandType commandType)
{
    _queueCommand.push_back(commandType);
}
