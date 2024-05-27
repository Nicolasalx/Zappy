/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** forward
*/

#include "postCommand.hpp"

void Ai::PostCommand::forward(Ai::Client &client)
{
    char command[] = "Forward\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(FORWARD);
    client.disableSendCommand();
}
