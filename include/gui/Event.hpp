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
    #include "InfoGame.hpp"

namespace Gui
{
    struct Event
    {
        std::vector<Gui::EventType> eventType;
        std::string buffer;
        Pos mouse = {0, 0};
        Size windowSize = {0, 0};
        double frame_time = 0;
        RayInfoData rayInfo;
        Pos playerPos;
        bool isKeyDown;
    };
}

#endif /* !EVENT_HPP_ */
