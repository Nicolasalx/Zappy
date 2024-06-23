/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "Client.hpp"
#include "Core.hpp"

int main(int argc, char const *argv[], char **env)
{
    Gui::Core core;

    try {
        core.parseArgs(argc, argv, env);
        core.launch();
        core.loop();
    } catch (std::exception &exception) {
        my::log::error(exception.what());
        return 84;
    }
    return 0;
}
