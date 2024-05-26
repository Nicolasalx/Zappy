/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parseOrientation
*/

#include "getCommand.hpp"

Ai::Orientation Ai::GetCommand::analyseOrientation(const std::string orientationStr)
{
    int orientationNb = Ai::Client::getInt(orientationStr);

    Orientation orientation;

    switch (orientationNb) {
        case 0:
            orientation = ACTUAL_PLACE;
            break;
        case 1:
            orientation = NORTH;
            break;
        case 2:
            orientation = NORTH_EAST;
            break;
        case 3:
            orientation = EAST;
            break;
        case 4:
            orientation = SOUTH_EAST;
            break;
        case 5:
            orientation = SOUTH;
            break;
        case 6:
            orientation = SOUTH_WEST;
            break;
        case 7:
            orientation = WEST;
            break;
        case 8:
            orientation = NORTH_WEST;
            break;
    }
    return orientation;
}
