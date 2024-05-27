/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** displayHelp
*/

#include "client.hpp"

void Ai::Client::displayHelp()
{
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::exit(0);
}
