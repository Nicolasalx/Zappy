/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-guillaume.dubuis
** File description:
** loop
*/

#include "Core.hpp"
#include "FrameRate.hpp"

/*void Gui::Graphic::loop()
{
    auto next_frame = std::chrono::system_clock::now();
    while (1) {
        next_frame += std::chrono::milliseconds(1000 / 60);
        Gui::Event listEvent = this->actual_graphic->getEvent();
        const Gui::GameData &data = this->actual_game->update(listEvent);
        this->actual_graphic->render(data);
        std::this_thread::sleep_until(next_frame);
    }
}*/

void Gui::Core::parseArgs(int argc, const char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i] == std::string("-p")) {
            if (i + 1 >= argc)
                throw my::tracked_exception("Invalid Port.\n");
            this->port = argv[i + 1];
        }
        if (argv[i] == std::string("-h")) {
            if (i + 1 >= argc)
                throw my::tracked_exception("Invalid Ip.\n");
            this->ip = argv[i + 1];
        }
        if (argv[i] == std::string("-help")) {
            std::cout << "USAGE: ./zappy_gui -p port -h ip" << std::endl;
            std::exit(0);
        }
    }
    if (this->ip == "localhost") {
        this->ip = "127.0.0.1";
    }
}

void Gui::Core::launch()
{
    this->renderLoader.load("./my_zappy_gui/raylib_render/raylib_render.so");
    this->clientLoader.load("./my_zappy_gui/client/client.so");

    this->renderModule = std::shared_ptr<Gui::IRenderModule>(this->renderLoader.getInstance("entryPoint"));
    this->clientModule = std::shared_ptr<Gui::IClient>(this->clientLoader.getInstance("entryPoint"));

    this->gameModule = std::make_shared<Gui::Zappy>(this->clientModule, this->gameData);
}

bool Gui::Core::eventContain(const Gui::Event &eventList, const Gui::EventType &eventType)
{
    for (const Gui::EventType &eventIt : eventList.eventType) {
        if (eventIt == eventType) {
            return true;
        }
    }
    return false;
}

bool Gui::Core::handleCoreEvent(const Gui::Event &eventList)
{
    for (const Gui::EventType &event : eventList.eventType) {
        if (event == Gui::EventType::EXIT) {
            return true;
        }
        if (event == Gui::EventType::NEXT_DISPLAY) {
            if (!this->displayType) {
                this->renderModule.reset();
                this->renderLoader.close();
                this->renderLoader.load("./my_zappy_gui/sfml_render/sfml_render.so");
                this->renderModule = std::unique_ptr<Gui::IRenderModule>(this->renderLoader.getInstance("entryPoint"));
                this->displayType = !this->displayType;
                break;
            } else {
                this->renderModule.reset();
                this->renderLoader.close();
                this->renderLoader.load("./my_zappy_gui/raylib_render/raylib_render.so");
                this->renderModule = std::unique_ptr<Gui::IRenderModule>(this->renderLoader.getInstance("entryPoint"));
                this->displayType = !this->displayType;
                break;
            }
        }
    }
    return false;
}

void Gui::Core::handleGameState()
{
    if (this->gameData->dataMenu.stateGame == TRY_SPECTATOR_MODE) {
        try {
            this->clientModule->connect(
                !this->gameData->dataMenu.dataConnection.ip.empty() ? gameData->dataMenu.dataConnection.ip : this->ip,
                !gameData->dataMenu.dataConnection.port.empty() ? gameData->dataMenu.dataConnection.port : this->port
            );
            this->clientModule->send("GRAPHIC\n");
            _isConnectedToServer = true;
        } catch (...) {
            std::cerr << "An unknown error occurred." << std::endl;
            this->gameData->dataMenu.stateGame = Gui::CONNECTION_FAILED_MENU;
            return;
        }
        this->gameData->dataMenu.stateGame = IN_SPECTATOR_MODE;
    }
    if (this->gameData->dataMenu.stateGame == TRY_PLAYER_MODE) {
        try {
            this->clientModule->connect(
                !this->gameData->dataMenu.dataConnection.ip.empty() ? gameData->dataMenu.dataConnection.ip : this->ip,
                !gameData->dataMenu.dataConnection.port.empty() ? gameData->dataMenu.dataConnection.port : this->port
            );
            this->clientModule->send(gameData->dataMenu.dataConnection.teamName);
            _isConnectedToServer = true;
        } catch (...) {
            std::cerr << "An unknown error occurred." << std::endl;
            this->gameData->dataMenu.stateGame = Gui::CONNECTION_FAILED_MENU;
            return;
        }
        this->gameData->dataMenu.stateGame = IN_PLAYER_MODE;
    }
}

std::vector<std::string> Gui::Core::recvMessages()
{
    std::vector<std::string> messages;
    try {
        messages = this->clientModule->recv();
    } catch (...) {
        this->gameData->dataMenu.stateGame = Gui::CONNECTION_FAILED_MENU;
    }
    return messages;
}

void Gui::Core::loop()
{
    Gui::FrameRate::setFrameRate(60);

    while (true) {
        Gui::FrameRate::start();
        std::vector<std::string> messRecv;

        if (_isConnectedToServer) {
            messRecv = recvMessages();
        }
        const Gui::Event &eventList = this->renderModule->getEvent();

        if (handleCoreEvent(eventList)) {
            break;
        }
        handleGameState();
        this->gameModule->update(messRecv, eventList);
        this->renderModule->render(*this->gameData.get());
        Gui::FrameRate::end();
    }
}
