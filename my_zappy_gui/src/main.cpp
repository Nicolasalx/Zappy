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
        std::thread client_thread(Client, std::make_shared<>(), argc, argv);
        std::thread graphic_thread(Graphic, std::make_shared<>());

        graphic_thread.join();
        client_thread.join();
//        Gui::Client client(argc, argv);
//        client.create_client();
//        client.launch_client();
    } catch (my::tracked_exception &e) {
        my::log::error(e.what());
        return 84;
    }
    return 0;
}
