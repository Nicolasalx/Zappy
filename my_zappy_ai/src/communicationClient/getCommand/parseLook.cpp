/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseLook
*/

#include "getCommand.hpp"

void Ai::GetCommand::parseLook(Client &client, const std::string &reply_data, Player &player)
{
    (void) reply_data;
    (void) player;
    client.enableSendCommand();
}
