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

void Client::get_args(int argc, const char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i] == std::string("-p")) {
            if (i + 1 >= argc)
                throw my::tracked_exception("Invalid Port.\n");
            this->port = std::atoi(argv[i + 1]);
        }
        if (argv[i] == std::string("-h")) {
            if (i + 1 >= argc)
                throw my::tracked_exception("Invalid Ip.\n");
            this->ip = argv[i + 1];
        }
        if (argv[i] == std::string("-help")) {
            std::cout << "USAGE: ./zappy_gui -p port -h ip" << std::endl;
            exit(0);
        }
    }
    if (this->ip == "localhost") {
        this->ip = "127.0.0.1";
    }
}

Client::Client(int argc, const char **argv)
{
    this->ip = "127.0.0.1";
    this->port = 8080;
    this->get_args(argc, argv);
    if (inet_aton(this->ip.c_str(), &this->server_address.sin_addr) == 0) {
        throw my::tracked_exception("Invalid Ip.\n");
    }
    this->launch_graphic();
}
