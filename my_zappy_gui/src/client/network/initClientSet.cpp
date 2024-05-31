/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_client_set
*/

#include "zappy_gui.hpp"

void Gui::Client::init_client_set()
{
    FD_ZERO(&this->read_set);
    FD_SET(STDIN_FILENO, &this->read_set);
    FD_SET(this->fd, &this->read_set);
    FD_ZERO(&this->write_set);
    FD_SET(this->fd, &this->write_set);
    this->max_fd = this->fd;
}

void Gui::Client::monitor_input()
{
    if (select(max_fd + 1, &this->read_set,
        &this->write_set, NULL, NULL) == -1) {
        throw my::tracked_exception("Select failed.\n");
    }
}
