/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** linkTeam
*/

#include "postCommand.hpp"

void Ai::PostCommand::linkTeam(Ai::Client &client)
{
    const std::string teamName = client.getTeamName();
    std::string commandString = teamName + "\n";

    char command[commandString.size() + 1];
    std::strcpy(command, commandString.c_str());

    client.sendCmdToServer(command, sizeof(command) - 1);
    client.insertInQueue(TEAM);
    client.disableSendCommand();
}
