/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_client_set
*/

#include "zappyAi.hpp"

void Ai::Client::initClientSet()
{
    FD_ZERO(&this->readSet);
    FD_SET(STDIN_FILENO, &this->readSet);
    FD_SET(this->fd, &this->readSet);
    FD_ZERO(&this->writeSet);
    FD_SET(this->fd, &this->writeSet);
    this->maxFd = this->fd;
}

void Ai::Client::monitorInput()
{
    if (select(maxFd + 1, &this->readSet,
        &this->writeSet, NULL, NULL) == -1) {
        throw my::tracked_exception("Select failed.\n");
    }
}
