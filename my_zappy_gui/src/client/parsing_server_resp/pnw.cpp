/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pnw
*/

#include "zappy_gui.hpp"

void Gui::GameState::pnw(std::vector<std::string> args)
{
    if (args.size() != 6)
        return;
    std::cout << "pnw" << std::endl;
    for (auto arg : args) {
        std::cout << arg << std::endl;
    }
    player_t new_player;
    new_player.n = std::stoi(args[0]);
    new_player.pos.x = std::stoi(args[1]);
    new_player.pos.y = std::stoi(args[2]);
    new_player.real_pos.x = std::stoi(args[1]);
    new_player.real_pos.y = std::stoi(args[2]);
    new_player.orientation = std::stoi(args[3]);
    new_player.real_orientation = std::stoi(args[3]);
    new_player.level = std::stoi(args[4]);
    new_player.team_name = args[5];
    new_player.animation_nbr = 0;
    new_player.anim_frame_counter = 32;
    for (int i = 0; i < 7; i++) {
        new_player.inventory.push_back(0);
    }
    this->players_list.push_back(new_player);
}
