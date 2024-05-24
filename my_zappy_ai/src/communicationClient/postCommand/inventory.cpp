/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** inventory
*/

#include "zappyAi.hpp"

void Ai::PostCommand::inventory(Ai::Client &client)
{
    char command[] = "Inventory\n";

    client.sendCmdToServer(command, sizeof(command) - 1);
    client.insertInQueue(INVENTORY);
    client.disableSendCommand();
}
