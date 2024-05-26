/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_client
*/

#include "client.hpp"
#include "zappyAi.hpp"

void closeClient(int)
{
    std::cout << "Client closed." << std::endl;
    std::exit(0);
}

void Ai::Client::launchClient()
{
    Ai::Player player(*this);

    std::signal(SIGINT, closeClient);
    while (true) {
        initClientSet();
        monitorInput();
        handleNewInput();
        handleNewMessage(player);
        player.engineAI(*this);
    }
}
