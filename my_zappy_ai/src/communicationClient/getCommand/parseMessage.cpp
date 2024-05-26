/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseLook
*/

#include "getCommand.hpp"
#include "split_string.hpp"

bool Ai::GetCommand::parseMessage(const std::string &replyData, Player &player)
{
    Message message;

    std::vector<std::string> vectorMessage;
    my::split_string(replyData, " ", vectorMessage);
    if (vectorMessage.size() == 3 && vectorMessage.at(0) == "message") {
        message.orientation = analyseOrientation(vectorMessage.at(1));
        message.message = removeChar(vectorMessage.at(2), ',');
        player.setNewMessage(message);
        return true;
    }
    return false;
}
