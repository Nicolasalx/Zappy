/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy_gui.hpp
*/

#ifndef ZAPPY_GUI_H_
    #define ZAPPY_GUI_H_

    #include "my_tracked_exception.hpp"
    #include "my_log.hpp"
    #include <chrono>
    #include <unistd.h>
    #include <iostream>
    #include <string>
    #include <memory>
    #include <vector>
    #include <map>
    #include <functional>
    #include "Zappy.hpp"
    #include "Raylib.hpp"
    #include <thread>

namespace Gui
{
    class Graphic {
        public:
        Graphic();
        ~Graphic() = default;

        void loop();

        std::shared_ptr<Zappy> actual_game; //changer plus tard par IGameModule
        std::shared_ptr<Raylib> actual_graphic; // changer plus tard par IRenderModule
    };
}

#endif /* !ZAPPY_GUI_H_ */
