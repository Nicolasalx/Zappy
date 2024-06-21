/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parsing
*/

#include "Parser.hpp"

Gui::Parser::Parser(std::shared_ptr<GameData> gameData) : _gameData(std::move(gameData))
{
    _cmdMap.emplace("msz", [this](const std::vector<std::string> &args) { this->msz(args); });
    _cmdMap.emplace("bct", [this](const std::vector<std::string> &args) { this->bct(args); });
    _cmdMap.emplace("tna", [this](const std::vector<std::string> &args) { this->tna(args); });
    _cmdMap.emplace("pnw", [this](const std::vector<std::string> &args) { this->pnw(args); });
    _cmdMap.emplace("ppo", [this](const std::vector<std::string> &args) { this->ppo(args); });
    _cmdMap.emplace("plv", [this](const std::vector<std::string> &args) { this->plv(args); });
    _cmdMap.emplace("pin", [this](const std::vector<std::string> &args) { this->pin(args); });
    _cmdMap.emplace("pex", [this](const std::vector<std::string> &args) { this->pex(args); });
    _cmdMap.emplace("pbc", [this](const std::vector<std::string> &args) { this->pbc(args); });
    _cmdMap.emplace("pic", [this](const std::vector<std::string> &args) { this->pic(args); });
    _cmdMap.emplace("pie", [this](const std::vector<std::string> &args) { this->pie(args); });
    _cmdMap.emplace("pfk", [this](const std::vector<std::string> &args) { this->pfk(args); });
    _cmdMap.emplace("pdr", [this](const std::vector<std::string> &args) { this->pdr(args); });
    _cmdMap.emplace("pgt", [this](const std::vector<std::string> &args) { this->pgt(args); });
    _cmdMap.emplace("pdi", [this](const std::vector<std::string> &args) { this->pdi(args); });
    _cmdMap.emplace("enw", [this](const std::vector<std::string> &args) { this->enw(args); });
    _cmdMap.emplace("ebo", [this](const std::vector<std::string> &args) { this->ebo(args); });
    _cmdMap.emplace("edi", [this](const std::vector<std::string> &args) { this->edi(args); });
    _cmdMap.emplace("sgt", [this](const std::vector<std::string> &args) { this->sgt(args); });
    _cmdMap.emplace("sst", [this](const std::vector<std::string> &args) { this->sst(args); });
    _cmdMap.emplace("seg", [this](const std::vector<std::string> &args) { this->seg(args); });
    _cmdMap.emplace("smg", [this](const std::vector<std::string> &args) { this->smg(args); });
    _cmdMap.emplace("suc", [this](const std::vector<std::string> &args) { this->suc(args); });
    _cmdMap.emplace("sbp", [this](const std::vector<std::string> &args) { this->sbp(args); });
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
