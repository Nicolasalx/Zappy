/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pbc
*/

#include "Parser.hpp"

void Gui::Parser::pbc(std::vector<std::string> args)
{
    for (size_t i = 1; i < args.size(); ++i) {
        this->_gameData->broadcastResp.push_back(args[i]);
    }
}
