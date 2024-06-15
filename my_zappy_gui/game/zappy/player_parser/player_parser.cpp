/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player_parser
*/

#include "PlayerParser.hpp"

Gui::PlayerParser::PlayerParser(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    _replyHandler.emplace(Gui::PlayerCmd::WELCOME, [this](std::string) {});
    _replyHandler.emplace(Gui::PlayerCmd::CLIENT_NUM, [this](std::string) {});
    _replyHandler.emplace(Gui::PlayerCmd::MAP_SIZE, [this](std::string args) { this->mapSizeReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::FORWARD, [this](std::string args) { this->forwardReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::RIGHT, [this](std::string args) { this->rightReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::LEFT, [this](std::string args) { this->leftReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::LOOK, [this](std::string args) { this->lookReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::INVENTORY, [this](std::string args) { this->inventoryReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::BROADCAST, [this](std::string args) { this->broadcastReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::CONNECT_NBR, [this](std::string args) { this->connectNbrReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::FORK, [this](std::string args) { this->forkReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::EJECT, [this](std::string args) { this->ejectReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::TAKE, [this](std::string args) { this->takeReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::SET, [this](std::string args) { this->setReply(args); });
    _replyHandler.emplace(Gui::PlayerCmd::INCANTATION, [this](std::string args) { this->incantationReply(args); });

    this->_sendedMessage.push(Gui::PlayerCmd::WELCOME);
    this->_sendedMessage.push(Gui::PlayerCmd::CLIENT_NUM);
    this->_sendedMessage.push(Gui::PlayerCmd::MAP_SIZE);
}

void Gui::PlayerParser::update(std::vector<std::string> &messRecv)
{
    for (auto &msg : messRecv) {
        std::cout << msg;
        this->parse_server_reply(msg);
    }
}

void Gui::PlayerParser::parse_server_reply(std::string reply_data)
{
    if (reply_data == "End of Game\n") {

    } else if (reply_data.compare(0, 7, "eject: ") == 0) {

    } else if (reply_data.compare(0, 8, "message ") == 0) {

    } else if (reply_data == "dead\n") {

    } else if (reply_data == "Elevation underway\n") {

    } else {
        if (this->_sendedMessage.empty()) {
            std::cout << "[WARNING] ignored message: " << reply_data;
            return;
        }
        this->_replyHandler.at(this->_sendedMessage.front())(reply_data);
        this->_sendedMessage.pop();
    }
}
