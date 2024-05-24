/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look
*/

#include "zappyAi.hpp"

void Ai::PostCommand::look(Ai::Client &client)
{
    char command[] = "Look\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(LOOK);
    client.disableSendCommand();
}
