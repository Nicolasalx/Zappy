/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_gui.hpp"

int main(int argc, char const *argv[])
{
    try {
        Gui::Client client(argc, argv);
        client.create_client();
        client.launch_client();
    } catch (my::tracked_exception &e) {
        my::log::error(e.what());
        return 84;
    }
    return 0;
}
