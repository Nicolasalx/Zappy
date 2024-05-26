/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** eject
*/

#include "postCommand.hpp"

void Ai::PostCommand::eject(Ai::Client &client)
{
    char command[] = "Eject\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(EJECT);
    client.disableSendCommand();
}
