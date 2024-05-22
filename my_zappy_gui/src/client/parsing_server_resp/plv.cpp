/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** plv
*/

#include "zappy_gui.hpp"

void GameState::plv(std::vector<std::string> args)
{
    if (args.size() != 2)
        return;
    int player_id = std::stoi(args[0]);
    for (auto it = this->players_list.begin(); it != this->players_list.end(); it++) {
        if (it->n == player_id) {
            it->level = std::stoi(args[1]);
            break;
        }
    }
}