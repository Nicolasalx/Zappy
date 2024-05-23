/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_client
*/

#include "zappy_gui.hpp"
#include <signal.h>

void close_client(int)
{
    std::cout << "Client closed.\n";
    exit(0);
}

void Client::launch_client()
{
    signal(SIGINT, close_client);
    while (true) {
        init_client_set();
        monitor_input();
        handle_new_input();
        handle_new_message();
    }
}
