/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseForward
*/

#include "zappyAi.hpp"

void Ai::GetCommand::parseForward(Client &client, Player &player)
{
    std::vector<Tile> map;
    player.setMap(map);
    client.enableSendCommand();
}
