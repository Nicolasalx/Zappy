/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappy_gui.hpp"
#include <thread>
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
    this->graphic_thread = std::thread(&Client::launch_graphic, this);
    this->graphic_thread.detach();
}
