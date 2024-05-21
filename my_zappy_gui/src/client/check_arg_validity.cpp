/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_gui.hpp"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static void check_nb_arg(int argc)
{
    if (argc != 3) {
        std::cout <<
        "USAGE: ./myteams_cli ip port\n" <<
        "\tip is the server ip address on which the server socket listens.\n" <<
        "\tport is the port number on which the server socket listens.\n\n";
        throw my::tracked_exception("Too much or missing argument.\n");
    }
}

Client::Client(int argc, const char **argv)
{
    check_nb_arg(argc);
    std::string ip = argv[1];

    if (ip == "localhost") {
        inet_aton(argv[1], &this->server_address.sin_addr);
    } else {
        if (inet_aton(argv[1], &this->server_address.sin_addr) == 0) {
            std::cout << "Invalid Ip: " << argv[1] << std::endl;
            throw my::tracked_exception("Invalid Ip.\n");
        }
    }
    this->port = std::atoi(argv[2]);
    this->launch_graphic();
}
