/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** particle_system
*/

#include "zappy_gui.hpp"

void Gui::ParticleSystem::draw_particle(Camera3D camera)
{
    // std::cout << particle_systems.size() << std::endl;
    for (auto &particle_system : this->particle_systems) {
        particle_system.update_particle(this->_gameState->frame_time);
        particle_system.draw(this->particle_texture, camera);
    }
}
