/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parsing
*/

#include "Parser.hpp"

Gui::Parser::Parser(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    _cmdMap.emplace("msz", [this](std::vector<std::string> args) { this->msz(args); });
    _cmdMap.emplace("bct", [this](std::vector<std::string> args) { this->bct(args); });
    _cmdMap.emplace("tna", [this](std::vector<std::string> args) { this->tna(args); });
    _cmdMap.emplace("pnw", [this](std::vector<std::string> args) { this->pnw(args); });
    _cmdMap.emplace("ppo", [this](std::vector<std::string> args) { this->ppo(args); });
    _cmdMap.emplace("plv", [this](std::vector<std::string> args) { this->plv(args); });
    _cmdMap.emplace("pin", [this](std::vector<std::string> args) { this->pin(args); });
    _cmdMap.emplace("pic", [this](std::vector<std::string> args) { this->pic(args); });
    _cmdMap.emplace("pie", [this](std::vector<std::string> args) { this->pie(args); });
    _cmdMap.emplace("pdi", [this](std::vector<std::string> args) { this->pdi(args); });
    _cmdMap.emplace("enw", [this](std::vector<std::string> args) { this->enw(args); });
    _cmdMap.emplace("ebo", [this](std::vector<std::string> args) { this->ebo(args); });
    _cmdMap.emplace("edi", [this](std::vector<std::string> args) { this->edi(args); });
    _cmdMap.emplace("sgt", [this](std::vector<std::string> args) { this->sgt(args); });
    _cmdMap.emplace("smg", [this](std::vector<std::string> args) { this->smg(args); });
}

void Gui::Parser::parse_server_reply(std::string reply_data)
{
    std::string cmd;
    std::string type;
    std::vector<std::string> args;
    std::size_t pos = 0;

    while ((pos = reply_data.find('\n')) != std::string::npos) {
        cmd = reply_data.substr(0, pos);
        std::cout << "cmd: " << cmd << std::endl;
        this->_gameData->serverResp.push_back(cmd);
        type = cmd.substr(0, cmd.find(' '));
        cmd.erase(0, cmd.find(' ') + 1);
        while (cmd.find(' ') != std::string::npos) {
            args.push_back(cmd.substr(0, cmd.find(' ')));
            cmd.erase(0, cmd.find(' ') + 1);
        }
        args.push_back(cmd);
        if (_cmdMap.find(type) != _cmdMap.end()) {
            _cmdMap[type](args);
        }
        reply_data.erase(0, pos + 1);
        args.clear();
        if (this->_gameData->serverResp.size() > 30) {
            this->_gameData->serverResp.erase(this->_gameData->serverResp.begin());
        }
    }
}
