/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** getTeamName
*/

#include "zappy_ai.hpp"

void Ai::Client::getTeamName(int argc, const char **argv, int index)
{
    std::string nextArg = getNextArg(argc, argv, index);

    this->nameTeam = nextArg;
}
