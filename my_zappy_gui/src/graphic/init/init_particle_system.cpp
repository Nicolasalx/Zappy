/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** particle_system
*/

#include "zappy_gui.hpp"

ParticleSystem::ParticleSystem()
{
    this->velocity = 1.0f;
    this->max_particles = 20;
}

void Graphic::update_particle_list()
{
    while (this->particle_systems.size() != this->gameState->incant_list.size()) {
        if (this->particle_systems.size() < this->gameState->incant_list.size()) {
            this->particle_systems.push_back(ParticleSystem());
        } else {
            this->particle_systems.pop_back();
        }
        for (size_t i = 0; i < this->gameState->incant_list.size(); i++) {
            this->particle_systems[i].pos.x = this->gameState->incant_list[i].pos.x;
            this->particle_systems[i].pos.y = this->gameState->incant_list[i].pos.y;
        }
    }
}

// void ParticleSystem::update_particle()
// {
//     for (size_t i = 0; i < this->particles.size(); i++) {
//         particles
//     }
//     if (particles.size() < this->max_particles) {
//         particles.push_back
//     }
// }