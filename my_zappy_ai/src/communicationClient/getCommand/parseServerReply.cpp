/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseServerReply
*/

#include "zappyAi.hpp"

void Ai::GetCommand::parseResponseFormat()
{
    
}

void Ai::GetCommand::parseServerReply(Client &client, const std::string &reply_data, Player &player)
{
    std::list<Ai::CommandType> _queue = client.getQueue();

    if (_queue.empty()) {
        return;
    }

    Ai::CommandType cmdType = _queue.front();
    switch (cmdType) {
        case TEAM:
            std::cout << "TEAM PARSING!\n";
            player.setPlayerTeam();
            client.enableSendCommand();
            // Check ok / ko
            break;
        case FORWARD:
            std::cout << "FORWARD PARSING!\n";
            // Check ok
            client.enableSendCommand();
            break;
        case RIGHT:
            // Check ok
            client.enableSendCommand();
            break;
        case LEFT:
            client.enableSendCommand();
            // Check ok
            break;
        case LOOK:
            std::cout << "LOOK PARSING!\n";
            client.enableSendCommand();
            // Check Look Parsing
            break;
        case INVENTORY:
            this->parseInventory(reply_data, player);
            client.enableSendCommand();
            break;
        case BROADCAST_TEXT:
            // Check ok
            client.enableSendCommand();
            break;
        case CONNECT_NBR:
            // Check Number
            client.enableSendCommand();
            break;
        case FORK:
            // Check ok
            client.enableSendCommand();
            break;
        case EJECT:
            // Check ok
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
