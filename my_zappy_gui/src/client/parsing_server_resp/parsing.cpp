/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** parsing
*/

#include "zappy_gui.hpp"

GameState::GameState()
{
    cmd_map.emplace("msz", [this](std::vector<std::string> args) { this->msz(args); });
    cmd_map.emplace("sgt", [this](std::vector<std::string> args) { this->sgt(args); });
}

GameState::~GameState()
{
}

void GameState::parse_server_reply(std::string reply_data)
{
    std::string cmd;
    std::string type;
    std::vector<std::string> args;
    std::string::size_type pos = 0;

    while ((pos = reply_data.find("\n")) != std::string::npos) {
        cmd = reply_data.substr(0, pos);
        type = cmd.substr(0, cmd.find(" "));
        cmd.erase(0, cmd.find(" ") + 1);
        while (cmd.find(" ") != std::string::npos) {
            args.push_back(cmd.substr(0, cmd.find(" ")));
            cmd.erase(0, cmd.find(" ") + 1);
        }
        args.push_back(cmd);
        std::cout << "type: " << type << " args:";
        for (auto arg : args) {
            std::cout << " " << arg;
        }
        std::cout << std::endl;
        if (cmd_map.find(type) != cmd_map.end()) {
            cmd_map[type](args);
        }
        reply_data.erase(0, pos + 1);
        args.clear();
    }
}