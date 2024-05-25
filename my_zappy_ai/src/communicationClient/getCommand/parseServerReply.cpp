/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseServerReply
*/

#include "zappyAi.hpp"
#include "split_string.hpp"

bool Ai::GetCommand::checkMessage(const std::string &replyData)
{
    // Check => message <orientation>, <text> => Received a message
    std::vector<std::string> vectorMessage;
    my::split_string(replyData, " ", vectorMessage);
    if (vectorMessage.size() == 3 && vectorMessage.at(0) == "message") {
        // Continue to parse the string
        return true;
    }
    return false;
}

bool Ai::GetCommand::checkEjection(const std::string &replyData)
{
    // Check => eject: <number> => Player eject from direction
    std::vector<std::string> vectorEject;
    my::split_string(replyData, ":", vectorEject);
    if (vectorEject.size() == 2 && vectorEject.at(0) == "eject") {
        std::string strToClean = vectorEject.at(1);
        strToClean.erase(std::remove(strToClean.begin(), strToClean.end(), ' '), strToClean.end());

        // Get int from strToClean and after move the actual player to the case which depend of the destination
        // Check this enum for the number => orientation_t
        return true;
    }
    return false;
}

bool Ai::GetCommand::checkBasicEvent(const std::string &replyData)
{
    if (replyData == "dead") {
        std::exit(0); // Handle the death of the player
    }
    if (checkMessage(replyData)) {
        return true;
    }
    if (checkEjection(replyData)) {
        return true;
    }
    return false;
}

void Ai::GetCommand::parseServerReply(Client &client, const std::string &reply_data, Player &player)
{
    std::list<Ai::CommandType> _queue = client.getQueue();

    if (_queue.empty()) {
        return;
    }
    if (checkBasicEvent(reply_data)) {
        return;
    }
    Ai::CommandType cmdType = _queue.front();
    switch (cmdType) {
        case TEAM:
            // Check ok / ko -> What we do if ko

            // Si plus de place dans l'équipe -> Fork
            // TeamName existe pas -> Exit

            this->parseTeam(client, reply_data, player);
            break;
        case FORWARD:
            this->parseForward(client, player);
            break;
        case RIGHT:
            client.enableSendCommand();
            break;
        case LEFT:
            client.enableSendCommand();
            break;
        case LOOK:
            this->parseLook(client, reply_data, player);
            break;
        case INVENTORY:
            this->parseInventory(client, reply_data, player);
            break;
        case BROADCAST_TEXT:
            client.enableSendCommand();
            break;
        case CONNECT_NBR:
            this->parseNbSlotsUnused(client, reply_data, player);
            break;
        case FORK:
            client.enableSendCommand();
            break;
        case EJECT:
            // Check ok / ko
            client.enableSendCommand();
            break;
        case TAKE_OBJECT:
            // Check ok / ko
            client.enableSendCommand();
            break;
        case SET_OBJECT:
            // Check ok / ko
            client.enableSendCommand();
            break;
        case INCANTATION:
            // Check Elevation underway
            // Current level: (number) / ko
            client.enableSendCommand();
            break;
    }
    _queue.pop_front();
    client.setQueue(_queue);
    std::cout << reply_data << "\n";
}
