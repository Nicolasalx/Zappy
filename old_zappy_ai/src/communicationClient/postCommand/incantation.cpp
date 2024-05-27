/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation
*/

#include "postCommand.hpp"

void Ai::PostCommand::incantation(Ai::Client &client)
{
    char command[] = "Incantation\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(INCANTATION);
    client.disableSendCommand();
}
