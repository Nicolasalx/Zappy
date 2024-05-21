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
        for (std::string::size_type i = cmd.find(" ") + 1; i < cmd.size(); i++) {
            if (cmd[i] == ' ' || i == cmd.size() - 1) {
                args.push_back(cmd.substr(cmd.find(" ") + 1, i - cmd.find(" ") - 1));
            }
        }
        //std::cout << "cmd: " << cmd << std::endl;
        // std::cout << "type: " << type << std::endl;
        // std::cout << "args: " << args << std::endl;
        std::cout << "type: " << type << std::endl;
        for (auto arg : args) {
            std::cout << arg << " ";
        }
        std::cout << std::endl;
        // if (cmd_map.find(type) != cmd_map.end()) {
        //     cmd_map[type](args);
        // }
        reply_data.erase(0, pos + 1);
        args.clear();
    }
}