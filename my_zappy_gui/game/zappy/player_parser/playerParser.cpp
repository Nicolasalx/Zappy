/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player_parser
*/

#include <utility>

#include <utility>

#include "PlayerParser.hpp"

Gui::PlayerParser::PlayerParser(std::shared_ptr<GameData> gameData) : _gameData(std::move(std::move(gameData)))
{
    this->_sendedMessage = std::make_shared<std::queue<Gui::PlayerCmd>>();

    _replyHandler.emplace(Gui::PlayerCmd::WELCOME, [this](const std::string&) {});
    _replyHandler.emplace(Gui::PlayerCmd::CLIENT_NUM, [this](std::string args) { this->clientNumReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::MAP_SIZE, [this](std::string args) { this->mapSizeReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::FORWARD, [this](std::string args) { this->forwardReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::RIGHT, [this](std::string args) { this->rightReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::LEFT, [this](std::string args) { this->leftReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::LOOK, [this](std::string args) { this->lookReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::INVENTORY, [this](std::string args) { this->inventoryReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::BROADCAST, [this](std::string args) { this->broadcastReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::CONNECT_NBR, [this](std::string args) { this->connectNbrReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::FORK, [this](std::string args) { this->forkReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::EJECT, [this](std::string args) { this->ejectReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::TAKE, [this](std::string args) { this->takeReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::SET, [this](std::string args) { this->setReply(std::move(args)); });
    _replyHandler.emplace(Gui::PlayerCmd::INCANTATION, [this](std::string args) { this->incantationReply(std::move(args)); });

    this->_sendedMessage->push(Gui::PlayerCmd::WELCOME);
    this->_sendedMessage->push(Gui::PlayerCmd::CLIENT_NUM);
    this->_sendedMessage->push(Gui::PlayerCmd::MAP_SIZE);
}

std::shared_ptr<std::queue<Gui::PlayerCmd>> Gui::PlayerParser::getSendedMessage()
{
    return this->_sendedMessage;
}

void Gui::PlayerParser::update(std::vector<std::string> &messRecv)
{
    for (auto &msg : messRecv) {
        std::cout << msg;
        this->parse_server_reply(msg);
    }
}

void Gui::PlayerParser::parse_server_reply(const std::string &reply_data)
{
    this->_gameData->serverResp.push_back(reply_data);
    if (this->_gameData->serverResp.size() > 30) {
        this->_gameData->serverResp.erase(this->_gameData->serverResp.begin());
    }
    if (reply_data == "End of Game\n") {

    } else if (reply_data.compare(0, 7, "eject: ") == 0) {

    } else if (reply_data.compare(0, 8, "message ") == 0) {

    } else if (reply_data == "dead\n") {

    } else if (reply_data == "Elevation underway\n") {

    } else {
        if (this->_sendedMessage->empty()) {
            std::cout << "[WARNING] ignored message: " << reply_data;
            return;
        }
        this->_replyHandler.at(this->_sendedMessage->front())(reply_data);
        this->_sendedMessage->pop();
    }
}
