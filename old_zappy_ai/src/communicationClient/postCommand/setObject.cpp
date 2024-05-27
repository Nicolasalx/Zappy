/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** setObject
*/

#include "postCommand.hpp"

void Ai::PostCommand::setObject(Ai::Client &client, const std::string &object)
{
    std::string command_str = "Set " + object + "\n";
    char command[256];

    strcpy(command, command_str.c_str());
    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(SET_OBJECT);
    client.disableSendCommand();
}
