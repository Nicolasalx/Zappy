/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** left
*/

#include "postCommand.hpp"

void Ai::PostCommand::left(Ai::Client &client)
{
    char command[] = "Left\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(LEFT);
    client.disableSendCommand();
}
