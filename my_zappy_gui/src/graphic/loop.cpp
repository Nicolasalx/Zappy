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

void Gui::Graphic::start(int argc, const char **argv)
{
    // Argument parsing
}

void Gui::Graphic::launch()
{
    this->displayLoader.load("./lib/libDisplay.so"); // ! Replace the path
    this->gameLoader.load("./lib/libGame.so"); // ! Replace path

    this->displayModule = std::unique_ptr<Gui::IRenderModule>(this->displayLoader.getInstance("entryPoint"));
    this->gameModule = std::unique_ptr<Gui::IGameModule>(this->gameLoader.getInstance("entryPoint"));
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

        const Gui::Event &eventList = this->displayModule->getEvent();
        if (eventContain(eventList, Gui::EventType::EXIT)) {
            break;
        }
        handleCoreEvent(eventList);
        const GameData &data = this->gameModule->update(eventList);
        this->displayModule->render(data); // ! Implement this function in the raylib class

        Gui::FrameRate::end();
    }
}
