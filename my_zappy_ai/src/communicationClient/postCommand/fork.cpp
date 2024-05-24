/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** fork
*/

#include "zappyAi.hpp"

void Ai::PostCommand::fork(Ai::Client &client)
{
    char command[] = "Fork\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(FORK);
    client.disableSendCommand();
}
