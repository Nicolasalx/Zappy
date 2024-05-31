/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** particle_system
*/

#include "zappy_gui.hpp"

void Gui::Graphic::draw_particle()
{
    for (auto &particle_system : this->particle_systems) {
        particle_system.update_particle();
        particle_system.draw();
        std::cout << "draw particle" << std::endl;
    }
}