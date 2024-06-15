/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look_reply
*/

#include "PlayerParser.hpp"
#include "split_string.hpp"

void Gui::PlayerParser::lookReply(std::string args)
{
    std::vector<std::string> tile;
    std::vector<std::string> tileContent;
    std::array<std::array<int, 8>, 81> res;
    std::array<std::string, 8> resStr = {"player", "food",
        "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"};

    my::split_string(args, ",", tile);
    for (std::size_t i = 0; i < tile.size(); ++i) {
        my::split_string(tile[i], " ", tileContent);
        for (const std::string &ressource : tileContent) {
            for (std::size_t j = 0; j < resStr.size(); ++j) {
                if (ressource == resStr[j]) {
                    ++res[i][j];
                }
            }
        }
    }

    // update the ressource on tile with "res" array
}
