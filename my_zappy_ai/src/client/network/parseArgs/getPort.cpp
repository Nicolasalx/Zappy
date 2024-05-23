/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** getPort
*/

#include "zappy_ai.hpp"

void Ai::Client::getPort(int argc, const char **argv, int index)
{
    std::string nextArg = getNextArg(argc, argv, index);
    std::cout << "PORT: " << nextArg << "\n";
    int port_number = getInt(nextArg);

    if (port_number < 0 || port_number > MAX_PORT_NB) {
        throw my::tracked_exception("Port number out of range");
    }
    this->port = static_cast<unsigned short>(port_number);
}
