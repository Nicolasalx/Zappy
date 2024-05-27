/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseLook
*/

#include "getCommand.hpp"
#include "split_string.hpp"

bool Ai::GetCommand::parseEjection(const std::string &replyData, Player &player)
{
    // ! What we do with the orientation of eject (To see after).

    // Check => eject: <number> => Player eject from direction
    std::vector<std::string> vectorEject;
    my::split_string(replyData, ":", vectorEject);
    if (vectorEject.size() == 2 && vectorEject.at(0) == "eject") {
        std::string strToClean = vectorEject.at(1);
        strToClean.erase(std::remove(strToClean.begin(), strToClean.end(), ' '), strToClean.end());
        // Get int from strToClean and after move the actual player to the case which depend of the destination
        // Check this enum for the number => orientation_t

        player.setRefreshLook(true);
        return true;
    }
    return false;
}
