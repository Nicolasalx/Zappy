/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** client_num_reply
*/

#include "PlayerParser.hpp"

void Gui::PlayerParser::clientNumReply(std::string args)
{
    if (args == "ko\n") {
        while (!this->_sendedMessage.empty()) {
            this->_sendedMessage.pop();
        }
        this->_sendedMessage.push(Gui::PlayerCmd::WELCOME);
        this->_sendedMessage.push(Gui::PlayerCmd::CLIENT_NUM);
        this->_sendedMessage.push(Gui::PlayerCmd::MAP_SIZE);
        throw std::runtime_error("Not enought space in team\n");
    }
}
