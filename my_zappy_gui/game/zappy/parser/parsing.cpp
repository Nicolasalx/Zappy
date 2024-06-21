/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parsing
*/

#include <utility>

#include <utility>

#include "Parser.hpp"

Gui::Parser::Parser(std::shared_ptr<GameData> gameData) : _gameData(std::move(std::move(gameData)))
{
    _cmdMap.emplace("msz", [this](std::vector<std::string> args) { this->msz(std::move(args)); });
    _cmdMap.emplace("bct", [this](std::vector<std::string> args) { this->bct(std::move(args)); });
    _cmdMap.emplace("tna", [this](std::vector<std::string> args) { this->tna(std::move(args)); });
    _cmdMap.emplace("pnw", [this](std::vector<std::string> args) { this->pnw(std::move(args)); });
    _cmdMap.emplace("ppo", [this](std::vector<std::string> args) { this->ppo(std::move(args)); });
    _cmdMap.emplace("plv", [this](std::vector<std::string> args) { this->plv(std::move(args)); });
    _cmdMap.emplace("pin", [this](std::vector<std::string> args) { this->pin(std::move(args)); });
    _cmdMap.emplace("pex", [this](std::vector<std::string> args) { this->pex(std::move(args)); });
    _cmdMap.emplace("pbc", [this](std::vector<std::string> args) { this->pbc(std::move(args)); });
    _cmdMap.emplace("pic", [this](std::vector<std::string> args) { this->pic(std::move(args)); });
    _cmdMap.emplace("pie", [this](std::vector<std::string> args) { this->pie(std::move(args)); });
    _cmdMap.emplace("pfk", [this](std::vector<std::string> args) { this->pfk(std::move(args)); });
    _cmdMap.emplace("pdr", [this](std::vector<std::string> args) { this->pdr(std::move(args)); });
    _cmdMap.emplace("pgt", [this](std::vector<std::string> args) { this->pgt(std::move(args)); });
    _cmdMap.emplace("pdi", [this](std::vector<std::string> args) { this->pdi(std::move(args)); });
    _cmdMap.emplace("enw", [this](std::vector<std::string> args) { this->enw(std::move(args)); });
    _cmdMap.emplace("ebo", [this](std::vector<std::string> args) { this->ebo(std::move(args)); });
    _cmdMap.emplace("edi", [this](std::vector<std::string> args) { this->edi(std::move(args)); });
    _cmdMap.emplace("sgt", [this](std::vector<std::string> args) { this->sgt(std::move(args)); });
    _cmdMap.emplace("sst", [this](std::vector<std::string> args) { this->sst(std::move(args)); });
    _cmdMap.emplace("seg", [this](std::vector<std::string> args) { this->seg(std::move(args)); });
    _cmdMap.emplace("smg", [this](std::vector<std::string> args) { this->smg(std::move(args)); });
    _cmdMap.emplace("suc", [this](std::vector<std::string> args) { this->suc(std::move(args)); });
    _cmdMap.emplace("sbp", [this](std::vector<std::string> args) { this->sbp(std::move(args)); });
}

void Gui::Parser::update(std::vector<std::string> &messRecv)
{
    for (auto &mess : messRecv) {
        //std::cout << "cmd: " << mess;
        this->parse_server_reply(mess);
    }
}

void Gui::Parser::parse_server_reply(std::string reply_data)
{
    std::string cmd;
    std::string type;
    std::vector<std::string> args;
    std::size_t pos = 0;

    while ((pos = reply_data.find('\n')) != std::string::npos) {
        cmd = reply_data.substr(0, pos);
        this->_gameData->serverResp.push_back(cmd);
        type = cmd.substr(0, cmd.find(' '));
        cmd.erase(0, cmd.find(' ') + 1);
        while (cmd.find(' ') != std::string::npos) {
            args.push_back(cmd.substr(0, cmd.find(' ')));
            cmd.erase(0, cmd.find(' ') + 1);
        }
        args.push_back(cmd);
        if (_cmdMap.contains(type)) {
            _cmdMap.at(type)(args);
        }
        reply_data.erase(0, pos + 1);
        args.clear();
        if (this->_gameData->serverResp.size() > 30) {
            this->_gameData->serverResp.erase(this->_gameData->serverResp.begin());
        }
    }
}
