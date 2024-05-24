/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseInventory
*/

#include "zappyAi.hpp"
#include "split_string.hpp"

void Ai::GetCommand::extractItemInventory(const std::string &itemStr, Player &player)
{
    std::vector<std::string> itemSelectionned;
    my::split_string(itemStr, " ", itemSelectionned);

    if (itemSelectionned.size() != 2) {
        throw my::tracked_exception("A part of inventory has bad size !");
    }
    if (itemSelectionned.at(0) == "food") {
        int nbElement = Ai::Client::getInt(itemSelectionned.at(1));
        player.setElemToInventory(FOOD, nbElement);
    } else if (itemSelectionned.at(0) == "linemate") {
        int nbElement = Ai::Client::getInt(itemSelectionned.at(1));
        player.setElemToInventory(LINEMATE, nbElement);
    } else if (itemSelectionned.at(0) == "deraumere") {
        int nbElement = Ai::Client::getInt(itemSelectionned.at(1));
        player.setElemToInventory(DERAUMERE, nbElement);
    } else if (itemSelectionned.at(0) == "sibur") {
        int nbElement = Ai::Client::getInt(itemSelectionned.at(1));
        player.setElemToInventory(SIBUR, nbElement);
    } else if (itemSelectionned.at(0) == "mendiane") {
        int nbElement = Ai::Client::getInt(itemSelectionned.at(1));
        player.setElemToInventory(MENDIANE, nbElement);
    } else if (itemSelectionned.at(0) == "phiras") {
        int nbElement = Ai::Client::getInt(itemSelectionned.at(1));
        player.setElemToInventory(PHIRAS, nbElement);
    } else if (itemSelectionned.at(0) == "thystame") {
        int nbElement = Ai::Client::getInt(itemSelectionned.at(1));
        player.setElemToInventory(THYSTAME, nbElement);
    }
}

void Ai::GetCommand::parseInventory(const std::string &reply_data, Player &player)
{
    std::cout << "ENTER INVENTORY: " << reply_data << "\n";
    try {
        std::string extractedContent = extractContentBetweenBrackets(reply_data);

        std::vector<std::string> listItem;
        my::split_string(extractedContent, ",", listItem);

        std::cout << "CONTENT: " << extractedContent << "\n";
        std::cout << "SIZE: " << listItem.size() << "\n";


        if (listItem.size() != 7) {
            throw my::tracked_exception("Inventory gived is incorrect !");
        }
        for (const auto &item: listItem) {
            extractItemInventory(item, player);
        }
    } catch(const my::tracked_exception &exception) {
        std::cerr << exception.what() << '\n';
    }
}

