/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** sgt
*/

#include "Parser.hpp"

void Gui::Parser::sgt(std::vector<std::string> args)
{
    if (args.size() != 1) {
        return;
    }
    std::cout << "NEW FREQUENCY: " << args.at(0) << "\n";
    this->_gameData->timeUnit = std::stoi(args.at(0));
}
