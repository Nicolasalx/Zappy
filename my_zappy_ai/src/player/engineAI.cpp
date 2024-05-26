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
    }

    if (this->_refreshInventory) {
        this->sendCommand(INVENTORY);
        this->setRefreshInventory(false);
    }
    if (this->_refreshLook) {
        this->sendCommand(LOOK);
        this->setRefreshLook(false);
    }
    nextInstructionAi(client);
}

/*
    - Look:

    Rempli le vector de tile "_contentLook"
    Il est vider seulement si on refait Look ou Forward, on peut donc stocker les informations de la case et faire d'autres actions


*/
