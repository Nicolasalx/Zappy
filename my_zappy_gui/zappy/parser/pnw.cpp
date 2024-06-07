/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pnw
*/

#include "Parser.hpp"

void Gui::Parser::pnw(std::vector<std::string> args)
{
    if (args.size() != 6)
        return;
    // std::cout << "pnw" << std::endl;
    // for (auto arg : args) {
    //     std::cout << arg << std::endl;
    // }
    Player newPlayer;
    newPlayer.n = std::stoi(args[0]);
    newPlayer.pos.x = std::stoi(args[1]);
    newPlayer.pos.y = std::stoi(args[2]);
    newPlayer.real_pos.x = std::stoi(args[1]);
    newPlayer.real_pos.y = std::stoi(args[2]);
    newPlayer.orientation = std::stoi(args[3]);
    newPlayer.real_orientation = std::stoi(args[3]);
    newPlayer.level = std::stoi(args[4]);
    newPlayer.team_name = args[5];
    newPlayer.animation_nbr = 0;
    newPlayer.anim_frame_counter = 32;
    for (int i = 0; i < 7; i++) {
        newPlayer.inventory.push_back(0);
    }
    this->players_list.push_back(newPlayer);
}
