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
    std::shared_ptr<Gui::GameData> gameState = std::make_shared<Gui::GameData>();

    Gui::Graphic graphic;

    try {
        graphic.parseArgs(argc, argv);
        graphic.launch();
        graphic.loop();
    } catch (my::tracked_exception &e) {
        my::log::error(e.what());
        return 84;
    }
    return 0;
}
