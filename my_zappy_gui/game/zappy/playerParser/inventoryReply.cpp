/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** inventory_reply
*/

#include "PlayerParser.hpp"
#include <regex>

void Gui::PlayerParser::inventoryReply(std::string args)
{
    std::array<int, 7> ressource = {0};
    std::regex regex(R"(\b\d+\b)");

    std::size_t i = 0;
    for (auto it = std::sregex_iterator(args.begin(), args.end(), regex);
        it != std::sregex_iterator() && i < 7; ++it) {
        ressource[i] = std::stoi(it->str());
        ++i;
    }

    // update inventory with "ressource" array
    for (std::size_t i = 0; i < ressource.size(); ++i) {
        _gameData->playerList[0].inventory[i] = ressource[i];
    }
}
