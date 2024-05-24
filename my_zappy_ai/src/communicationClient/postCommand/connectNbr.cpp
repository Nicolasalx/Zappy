/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** connectNbr
*/

#include "zappyAi.hpp"

void Ai::PostCommand::connectNbr(Ai::Client &client)
{
    char command[] = "Connect_nbr\n";

    client.sendCmdToServer(command, sizeof(command));
    client.insertInQueue(CONNECT_NBR);
    client.disableSendCommand();
}
