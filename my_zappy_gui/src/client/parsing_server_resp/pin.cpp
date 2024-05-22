/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** pdi
*/

#include "zappy_gui.hpp"

void GameState::pin(std::vector<std::string> args)
{
    if (args.size() != 10)
        return;
    int player_id = std::stoi(args[0]);
    for (auto it = this->players_list.begin(); it != this->players_list.end(); it++) {
        if (it->n == player_id) {
            it->pos.x = std::stoi(args[1]);
            it->pos.y = std::stoi(args[2]);
            it->inventory[0] = std::stoi(args[3]);
            it->inventory[1] = std::stoi(args[4]);
            it->inventory[2] = std::stoi(args[5]);
            it->inventory[3] = std::stoi(args[6]);
            it->inventory[4] = std::stoi(args[7]);
            it->inventory[5] = std::stoi(args[8]);
            it->inventory[6] = std::stoi(args[9]);
            break;
        }
    }
    std::cout << "pin" << std::endl;
    for (auto arg : args) {
        std::cout << arg << std::endl;
    }
}