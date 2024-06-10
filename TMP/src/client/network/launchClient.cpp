/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launchClient
*/

#include "client.hpp"

void close_client(int)
{
    std::cout << "Client closed.\n";
    std::exit(0);
}

void Gui::Client::launchClient()
{
    signal(SIGINT, close_client);
    while (true) {
        initClientSet();
        monitorInput();
        handleNewInput();
        handleNewMessage();
    }
}
