/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** check_arg_validity
*/

#include "zappyAi.hpp"

void Ai::Client::getArgs(int argc, const char **argv)
{
    if (argc < 2) {
        throw my::tracked_exception("To few arguments gived.\n");
    }
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "-help") == 0) {
            displayHelp();
        } else if (std::strcmp(argv[i], "-p") == 0) {
            getPort(argc, argv, i);
        } else if (std::strcmp(argv[i], "-n") == 0) {
            getTeamNameParsing(argc, argv, i);
        } else if (std::strcmp(argv[i], "-h") == 0) {
            analyseIP(argc, argv, i);
        }
    }
}

Ai::Client::Client(int argc, const char **argv)
{
    this->ip = "127.0.0.1";
    this->port = 8080;
    this->getArgs(argc, argv);
    if (inet_aton(this->ip.c_str(), &this->serverAddress.sin_addr) == 0) {
        throw my::tracked_exception("Invalid Ip.\n");
    }
}
