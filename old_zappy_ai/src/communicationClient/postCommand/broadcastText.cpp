/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcastText
*/

#include "postCommand.hpp"

void Ai::PostCommand::broadcastText(Ai::Client &client, const std::string &text)
{
    std::string command_str = "Broadcast " + text + "\n";
    char command[256];

    strcpy(command, command_str.c_str());
    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(BROADCAST_TEXT);
    client.disableSendCommand();
}
