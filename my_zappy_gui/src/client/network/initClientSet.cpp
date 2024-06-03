/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initClientSet
*/

#include "client.hpp"

void Gui::Client::initClientSet()
{
    FD_ZERO(&this->read_set);
    FD_SET(STDIN_FILENO, &this->read_set);
    FD_SET(this->fd, &this->read_set);
    FD_ZERO(&this->write_set);
    FD_SET(this->fd, &this->write_set);
    this->max_fd = this->fd;
}

void Gui::Client::monitorInput()
{
    if (select(max_fd + 1, &this->read_set,
        &this->write_set, NULL, NULL) == -1) {
        throw my::tracked_exception("Select failed.\n");
    }
}
