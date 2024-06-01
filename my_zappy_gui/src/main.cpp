/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_gui.hpp"
#include "client.hpp"

int main(int argc, char const *argv[])
{
    Gui::GameState gameState;

    try {
        std::thread clientThread([](int argc, const char **argv, std::shared_ptr<Gui::GameState> gameState)
            {
                Gui::Client client(argc, argv, gameState);
            }, argc, argv, std::make_shared<Gui::GameState>(gameState));
        std::thread graphicThread([](std::shared_ptr<Gui::GameState> gameState)
            {
                Gui::Graphic graphic(gameState);
            }, std::make_shared<Gui::GameState>(gameState));
        graphicThread.join();
        clientThread.join();
    } catch (my::tracked_exception &e) {
        my::log::error(e.what());
        return 84;
    }
    return 0;
}
