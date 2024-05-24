/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** getTeamName
*/

#include "zappyAi.hpp"

void Ai::Client::getTeamNameParsing(int argc, const char **argv, int index)
{
    std::string nextArg = getNextArg(argc, argv, index);

    this->teamName = nextArg;
}
