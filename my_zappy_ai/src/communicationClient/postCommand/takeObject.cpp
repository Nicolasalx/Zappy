/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** takeObject
*/

#include "zappyAi.hpp"

void Ai::PostCommand::takeObject(Ai::Client &client)
{
    char command[] = "Take object\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(TAKE_OBJECT);
    client.disableSendCommand();
}
