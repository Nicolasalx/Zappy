/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** smg
*/

#include "zappy_gui.hpp"

void Gui::GameState::smg(std::vector<std::string> args)
{
    egg_t egg;
    egg.egg_number = std::stoi(args[0]);
    egg.pos.x = std::stoi(args[1]);
    egg.pos.y = std::stoi(args[2]);
    egg.player_number = -1;
    eggs_list.push_back(egg);
}