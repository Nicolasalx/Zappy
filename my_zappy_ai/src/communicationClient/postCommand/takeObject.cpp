/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** takeObject
*/

#include "postCommand.hpp"

void Ai::PostCommand::takeObject(Ai::Client &client, const std::string &object)
{
    std::string command_str = "Take " + object + "\n";
    char command[256];

    strcpy(command, command_str.c_str());
    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(TAKE_OBJECT);
    client.disableSendCommand();
}
