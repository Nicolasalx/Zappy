/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy
*/

#include "Zappy.hpp"

void Gui::Zappy::update(std::vector<std::string> &messRecv, const Gui::Event &event)
{
    this->_gameData->frameTime = event.frame_time;

    this->_parser.update(messRecv);

    this->_island.update(event);
    this->_object.update(event);
    this->_player.update(event);
    this->_egg.update(event);
    this->_menu.update(event);
}
