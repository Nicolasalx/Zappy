/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** postCommand
*/

#include "zappyAi.hpp"

void Ai::Player::sendCommand(const CommandType &commandType, const std::string &text)
{
    if (commandType != BROADCAST_TEXT) {
        return;
    }
    this->postCmd.broadcastText(_client, text);
}

void Ai::Player::sendCommand(const CommandType &commandType)
{
    switch (commandType) {
        case TEAM:
            this->postCmd.linkTeam(_client);
            break;
        case FORWARD:
            this->postCmd.forward(_client);
            break;
        case RIGHT:
            this->postCmd.right(_client);
            break;
        case LEFT:
            this->postCmd.left(_client);
            break;
        case LOOK:
            this->postCmd.look(_client);
            break;
        case INVENTORY:
            this->postCmd.inventory(_client);
            break;
        case CONNECT_NBR:
            this->postCmd.connectNbr(_client);
            break;
        case FORK:
            this->postCmd.fork(_client);
            break;
        case EJECT:
            this->postCmd.eject(_client);
            break;
        case TAKE_OBJECT:
            this->postCmd.takeObject(_client);
            break;
        case SET_OBJECT:
            this->postCmd.setObject(_client);
            break;
        case INCANTATION:
            this->postCmd.incantation(_client);
            break;
        default:
            break;
    }
}
