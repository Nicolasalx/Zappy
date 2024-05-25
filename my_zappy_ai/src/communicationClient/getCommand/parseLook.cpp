/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseLook
*/

#include "getCommand.hpp"
#include "split_string.hpp"

void Ai::GetCommand::parseOneTile(const std::string &tileStr, std::vector<Tile> &map)
{
    std::vector<std::string> listItem;
    my::split_string(tileStr, " ", listItem);
    Tile tile;

    for (const auto &item: listItem) {
        if (item == "food") {
            tile.elements.food += 1;
        } else if (item == "linemate") {
            tile.elements.linemate += 1;
        } else if (item == "deraumere") {
            tile.elements.deraumere += 1;
        } else if (item == "sibur") {
            tile.elements.sibur += 1;
        } else if (item == "mendiane") {
            tile.elements.mendiane += 1;
        } else if (item == "phiras") {
            tile.elements.phiras += 1;
        } else if (item == "thystame") {
            tile.elements.thystame += 1;
        } else if (item == "player") {
            tile.player += 1;
        }
    }
    map.push_back(tile);
}

void Ai::GetCommand::parseLook(Client &client, const std::string &reply_data, Player &player)
{
    std::vector<Tile> map;
    std::string extractedContent = extractContentBetweenBrackets(reply_data);

    player.setMap(map); // reset map before add new map
    std::vector<std::string> listTile;
    my::split_string(extractedContent, ",", listTile);

    for (const auto &tile: listTile) {
        parseOneTile(tile, map);
    }
    player.setMap(map);
    client.enableSendCommand();
}
