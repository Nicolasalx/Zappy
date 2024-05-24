/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_ai
*/

#include "zappyAi.hpp"

void Ai::Player::engineAI(Client &client)
{
    if (!client.isConnected() || client.canSendCommand() == false) {
        return;
    }
    if (!this->_clientHasaTeam) {
        this->postCmd.linkTeam(client);

        this->postCmd.inventory(client);
    }

//    char command[] = "Team1\n";
//    client.sendCmdToServer(command, sizeof(command));

    //sleep(1);
    //this->postCmd.inventory(client);

    //this->postCmd.forward(client);
    //sleep(1);
    //this->postCmd.look(client);
    //sleep(1);
    //this->postCmd.look(client);
}
