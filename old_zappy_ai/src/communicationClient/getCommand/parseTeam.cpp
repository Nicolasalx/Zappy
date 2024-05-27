/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseTeam
*/

#include "getCommand.hpp"
#include "split_string.hpp"

void Ai::GetCommand::parseTeam(Client &client, const std::string &reply_data, Player &player)
{
    try {
        std::vector<std::string> listItem;
        my::split_string(reply_data, "\n", listItem);
        if (listItem.size() != 2) {
            return;
        }
        int nbSlots = Ai::Client::getInt(listItem.at(0));
        std::vector<std::string> vectorDimension;
        my::split_string(listItem.at(1), " ", vectorDimension);
        if (vectorDimension.size() != 2) {
            return;
        }
        int xAxis = Ai::Client::getInt(vectorDimension.at(0));
        int yAxis = Ai::Client::getInt(vectorDimension.at(1));
        player.setDataTeam(nbSlots, xAxis, yAxis);
        client.enableSendCommand();
    } catch(const my::tracked_exception &exception) {
        std::cerr << exception.what() << '\n';
    }
}
