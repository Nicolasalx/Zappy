/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-guillaume.dubuis
** File description:
** loop
*/

#include "Graphic.hpp"
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

void Gui::Graphic::parseArgs(int argc, const char **argv)
{
    // Argument parsing
}

void Gui::Graphic::launch()
{
    // parsing Arguments
    this->renderLoader.load("./lib/render.so"); // ! Replace the path
    this->clientLoader.load("./my_zappy_gui/client/client.so");

    this->renderModule = std::unique_ptr<Gui::IRenderModule>(this->renderLoader.getInstance("entryPoint"));
    this->clientModule = std::unique_ptr<Gui::IClient>(this->clientLoader.getInstance("entryPoint"));

    this->gameModule = std::make_shared<Gui::Zappy>(this->clientModule);

    this->clientModule->connect("127.0.0.1", "4242");
}

bool Gui::Graphic::eventContain(const Gui::Event &eventList, const Gui::EventType &eventType)
{
    for (const Gui::EventType &eventIt : eventList.eventType) {
        if (eventIt == eventType) {
            return true;
        }
    }
    return false;
}

void Gui::Graphic::handleCoreEvent(const Gui::Event &eventList)
{
    // if (eventContain(eventList, Gui::EventType::NEXT_GAME)) {
    //     loadNextGame();
    // } else if (eventContain(eventList, Gui::EventType::NEXT_DISPLAY)) {
    //     loadNextDisplay();
    // } else if (eventContain(eventList, Gui::EventType::BACK_MENU)) {
    //     loadMenu();
    // } else if (eventContain(eventList, Gui::EventType::RESTART)) {
    //     loadSelectedGame();
    // }
}

void Gui::Graphic::loop()
{
    Gui::FrameRate::setFrameRate(30);

    while (true) {
        Gui::FrameRate::start();

        std::vector<std::string> messRecv = this->clientModule->recv();
        const Gui::Event &eventList = this->renderModule->getEvent();

        const GameData &data = this->gameModule->update(messRecv, eventList);
        this->renderModule->render(data);

        Gui::FrameRate::end();
    }
}
