/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseServerReply
*/

#include "zappyAi.hpp"
#include "getCommand.hpp"
#include "split_string.hpp"
#include "orientation.hpp"

bool Ai::GetCommand::checkBasicEvent(const std::string &replyData, Player &player)
{
    if (this->parseMessage(replyData, player)) {
        return true;
    }
    if (this->parseEjection(replyData, player)) {
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
    if (checkBasicEvent(reply_data, player)) {
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
            client.enableSendCommand();
            break;
        case TAKE_OBJECT:
            player.setRefreshInventory(true);
            client.enableSendCommand();
            break;
        case SET_OBJECT:
            player.setRefreshInventory(true);
            client.enableSendCommand();
            break;
        case INCANTATION:
            this->parseIncantation(reply_data, client, _queue, player);
            break;
    }
    if (cmdType != INCANTATION) {
        _queue.pop_front();
    }
    client.setQueue(_queue);
    std::cout << reply_data << "\n";
}
