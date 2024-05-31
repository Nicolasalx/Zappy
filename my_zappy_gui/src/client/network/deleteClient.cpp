/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** delete_client
*/

#include "client.hpp"

Gui::Client::~Client()
{
    if (this->fd > 0)
        close(this->fd);
}