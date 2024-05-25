/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_ai
*/

#include "zappyAi.hpp"

void Ai::Player::nextInstructionAi(Client &client)
{
    client = _client;
}

void Ai::Player::engineAI(Client &client)
{
    _client = client;
    if (!client.isConnected() || client.canSendCommand() == false) {
        nextInstructionAi(client);
        return;
    }
    if (!this->_clientHasaTeam) {
        this->sendCommand(TEAM);
        this->sendCommand(LOOK);
        // this->sendCommand(INVENTORY);
        // this->sendCommand(FORWARD);
        // this->sendCommand(INVENTORY);
    }
    nextInstructionAi(client);
}
