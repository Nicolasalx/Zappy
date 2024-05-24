/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcastText
*/

#include "zappyAi.hpp"

void Ai::PostCommand::broadcastText(Ai::Client &client)
{
    char command[] = "Broadcast text\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(BROADCAST_TEXT);
    client.disableSendCommand();
}
