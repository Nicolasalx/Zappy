/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** commandType
*/

#ifndef COMMANDTYPE_H_
    #define COMMANDTYPE_H_

namespace Ai
{
    enum CommandType {
        TEAM,
        FORWARD,
        RIGHT,
        LEFT,
        LOOK,
        INVENTORY,
        BROADCAST_TEXT,
        CONNECT_NBR,
        FORK,
        EJECT,
        TAKE_OBJECT,
        SET_OBJECT,
        INCANTATION
    };
}

#endif /* !COMMANDTYPE_H_ */