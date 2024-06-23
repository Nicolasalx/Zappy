/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Core
*/

#ifndef CORE_H_
    #define CORE_H_

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
    #include "GameData.hpp"
    #include "Zappy.hpp"
    #include "Raylib.hpp"
    #include <thread>
    #include "IRenderModule.hpp"
    #include "DLLoader.hpp"
    #include "IClient.hpp"

namespace Gui
{
    class Core {
        public:
            Core();
            ~Core();

            void parseArgs(int argc, const char **argv, char **env);
            void launch();
            void loop();

        private:
            bool eventContain(const Gui::Event &eventList, const Gui::EventType &eventType);
            bool handleCoreEvent(const Gui::Event &eventList);
            void handleGameState();
            std::vector<std::string> recvMessages();

            std::shared_ptr<Gui::IRenderModule> renderModule;
            std::shared_ptr<Gui::IClient> clientModule;

            std::shared_ptr<Gui::IGameModule> gameModule;

            Gui::DLLoader<Gui::IClient> clientLoader;
            Gui::DLLoader<Gui::IRenderModule> renderLoader;

            std::shared_ptr<Gui::GameData> gameData;

            std::string port = "4242";
            std::string ip = "127.0.0.1";

            bool _isConnectedToServer = false;

            bool displayType = false;
    };
}

#endif /* !CORE_H_ */
