/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pdi
*/

#include "zappy_gui.hpp"

void Gui::GameState::pdi(std::vector<std::string> args)
{
    if (args.size() != 1)
        return;
    int player_id = std::stoi(args[0]);
    for (auto it = this->players_list.begin(); it != this->players_list.end(); it++) {
        if (it->n == player_id) {
            this->players_list.erase(it);
            break;
        }
    }
}
