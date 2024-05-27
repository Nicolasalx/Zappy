/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** right
*/

#include "postCommand.hpp"

void Ai::PostCommand::right(Ai::Client &client)
{
    char command[] = "Right\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(RIGHT);
    client.disableSendCommand();
}
