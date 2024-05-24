/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** setObject
*/

#include "zappyAi.hpp"

void Ai::PostCommand::setObject(Ai::Client &client)
{
    char command[] = "Set object\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(SET_OBJECT);
    client.disableSendCommand();
}
