/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** particle_system
*/

#include "zappy_gui.hpp"

Gui::ParticleSystem::ParticleSystem()
{
    this->velocity = 1.0f;
    this->max_particles = 20;
}

void Gui::Graphic::update_particle_list()
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

void Gui::ParticleSystem::update_particle()
{
    for (auto &particle : particles) {
        particle += 0.1f;
    }
    if (particles.size() <= this->max_particles) {
        particles.push_front(0.0f);
    }
    if (particles.size() > this->max_particles) {
        particles.pop_back();
    }
}

void Gui::ParticleSystem::draw()
{
    for (auto &particle : particles) {
        DrawCircle3D((Vector3){pos.x * SCALE, particle, pos.y * SCALE}, 0.5f, (Vector3){0, 0, 0}, 0, RED);
    }
}