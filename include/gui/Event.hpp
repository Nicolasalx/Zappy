/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_

    #include "EventType.hpp"
    #include <string>
    #include <vector>

namespace Gui
{
    struct Event
    {
        std::vector<Gui::EventType> eventType;
        std::string buffer;
        int mouse_x = 0;
        int mouse_y = 0;
        int window_size_x = 0;
        int window_size_y = 0;
        double frame_time = 0;
    };
}

#endif /* !EVENT_HPP_ */
