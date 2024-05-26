/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseNbSlotsUnused
*/

#include "getCommand.hpp"

void Ai::GetCommand::parseNbSlotsUnused(Client &client, const std::string &reply_data, Player &player)
{
    try {
        player.setNbUnusedSlots(Ai::Client::getInt(reply_data));
        client.enableSendCommand();
    } catch(const my::tracked_exception &exception) {
        std::cerr << exception.what() << '\n';
    }
}
