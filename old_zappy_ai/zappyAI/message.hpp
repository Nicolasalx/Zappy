/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** message
*/

#ifndef MESSAGE_H_
    #define MESSAGE_H_

    #include "orientation.hpp"
    #include <string>

namespace Ai
{
    struct Message {
        Orientation orientation;
        std::string message;
    };
}

#endif /* !MESSAGE_H_ */
