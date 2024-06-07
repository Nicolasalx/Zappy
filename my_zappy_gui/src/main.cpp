/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "Client.hpp"
#include "Graphic.hpp"

int main(int argc, char const *argv[])
{
    std::shared_ptr<Gui::GameState> gameState = std::make_shared<Gui::GameState>();

    try {
        std::thread clientThread([](int argc, const char **argv, std::shared_ptr<Gui::GameState> gameState)
            {
                Gui::Client client(argc, argv, gameState);
            }, argc, argv, gameState);
        std::thread graphicThread([](std::shared_ptr<Gui::GameState> gameState)
            {
                Gui::Graphic graphic(gameState);
            }, gameState);
        graphicThread.join();
        clientThread.join();

    } catch (my::tracked_exception &e) {
        my::log::error(e.what());
        return 84;
    }
    return 0;
}
