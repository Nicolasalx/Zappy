/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_graphic
*/

#include "zappy_gui.hpp"

void Client::launch_graphic()
{
    std::cout << "graphic launched\n";
    while (1) {
        for (auto &player : this->gameState.players_list) {
            std::cout << "Player " << player.n << " is at position " << player.pos.x << " " << player.pos.y << " and is level " << player.level << std::endl;
        }
        sleep(5);
    }
}