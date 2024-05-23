/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** displayHelp
*/

#include "zappy_ai.hpp"

void Ai::Client::displayHelp()
{
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::exit(0);
}
