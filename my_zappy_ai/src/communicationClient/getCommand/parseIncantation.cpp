/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseIncantation
*/

#include "getCommand.hpp"
#include "split_string.hpp"

void Ai::GetCommand::parseIncantation(const std::string &replyData, Client &client, std::list<Ai::CommandType> &queue, Player &player)
{
    if (replyData == "ko") {
        client.enableSendCommand();
        queue.pop_front();
    } else {
        std::vector<std::string> listStr;
        my::split_string(replyData, ":", listStr);
        if (this->removeChar(listStr.at(0), ' ') == "Current level") {
            std::string strCleaned = this->removeChar(listStr.at(1), ' ');
            player.setNewLevel(Ai::Client::getInt(strCleaned));
            client.enableSendCommand();
            queue.pop_front();
        }
    }
}
