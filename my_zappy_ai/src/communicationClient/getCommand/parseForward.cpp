/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseForward
*/

#include "getCommand.hpp"

void Ai::GetCommand::parseForward(Client &client, Player &player)
{
    player.setRefreshLook(true);
    client.enableSendCommand();
}
