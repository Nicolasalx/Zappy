/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** forward_reply
*/

#include "PlayerParser.hpp"

void Gui::PlayerParser::forwardReply(const std::string& args)
{
    if (args == "ok\n") {
        std::cout << "ANIMATION FORWARD\n";
        // go forward
    }
}
