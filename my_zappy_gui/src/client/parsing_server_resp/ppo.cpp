/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** ppo
*/

#include "zappy_gui.hpp"

void Gui::GameState::ppo(std::vector<std::string> args)
{
    if (args.size() != 4)
        return;
    int player_id = std::stoi(args[0]);
    for (auto it = this->players_list.begin(); it != this->players_list.end(); it++) {
        if (it->n == player_id) {
            it->pos.x = std::stoi(args[1]);
            it->pos.y = std::stoi(args[2]);
            it->orientation = std::stoi(args[3]);
            it->animation_nbr = 0;
            it->anim_frame_counter = 152;
            break;
        }
    }
}