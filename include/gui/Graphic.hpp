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
    #include "IRenderModule.hpp"
    #include "DLLoader.hpp"

namespace Gui
{
    class Graphic {
        public:
            Graphic();
            ~Graphic() = default;

            void start(int argc, const char **argv);
            void launch();
            void loop();

        private:
            bool eventContain(const Gui::Event &eventList, const Gui::EventType &eventType);
            void handleCoreEvent(const Gui::Event &eventList);

            std::unique_ptr<Gui::IRenderModule> displayModule;
            std::unique_ptr<Gui::IGameModule> gameModule;
            Gui::DLLoader<Gui::IRenderModule> displayLoader;
            Gui::DLLoader<Gui::IGameModule> gameLoader;

    };
}

#endif /* !ZAPPY_GUI_H_ */
