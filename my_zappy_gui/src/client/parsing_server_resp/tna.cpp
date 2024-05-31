/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tna
*/

#include "zappy_gui.hpp"

void Gui::GameState::tna(std::vector<std::string> args)
{
    for (auto team : args) {
        this->team_names.push_back(team);
    }
    // std::cout << "tna" << std::endl;
    // for (auto arg : args) {
    //     std::cout << arg << std::endl;
    // }
}
