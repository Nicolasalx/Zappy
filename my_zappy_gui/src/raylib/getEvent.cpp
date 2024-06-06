/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** getEvent
*/

#include "Raylib.hpp"

Gui::Event Gui::Raylib::getEvent()
{
    Gui::Event event;

    // ! handle event (see below what we had in arcade)
    // while (this->_window.pollEvent(this->_event)) {
    //     if (this->_event.type == sf::Event::Closed) {
    //         event.eventType.push_back(Gui::EventType::EXIT);
    //     }
    //     if (this->_ignoreKey) {
    //         this->putEventInBuffer(event);
    //     } else {
    //         this->putEventInEventList(event);
    //     }
    // }
    return event;
}
