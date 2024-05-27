/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** getTeamName
*/

#include "client.hpp"

void Ai::Client::getTeamNameParsing(int argc, const char **argv, int index)
{
    std::string nextArg = getNextArg(argc, argv, index);

    this->teamName = nextArg;
}
