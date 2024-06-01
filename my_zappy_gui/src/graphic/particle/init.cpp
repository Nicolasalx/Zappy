/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** particle_system
*/

#include "zappy_gui.hpp"

Gui::ParticleSystem::ParticleSystem()
{
    this->max_particles = 20;
    for (size_t i = 0; i < this->max_particles; i++) {
        particle_pos_t new_particle;
        new_particle.x = (std::rand() % 10 - 5) / 2.0f;
        new_particle.y = std::rand() % 7;
        new_particle.z = (std::rand() % 10 - 5) / 2.0f;
        particles.push_back(new_particle);
    }
}

void Gui::Graphic::update_particle_list()
{
    while (this->particle_systems.size() != this->gameState->incant_list.size()) {
        // std::cout << "update particle" << std::endl;
        if (this->particle_systems.size() < this->gameState->incant_list.size()) {
            this->particle_systems.push_back(ParticleSystem());
        } else {
            // std::cout << "destroy particle" << std::endl;
            this->particle_systems.pop_back();
        }
        for (size_t i = 0; i < this->gameState->incant_list.size() && i < particle_systems.size(); i++) {
            this->particle_systems[i].pos.x = this->gameState->incant_list[i].pos.x;
            this->particle_systems[i].pos.y = this->gameState->incant_list[i].pos.y;
        }
    }
}

void Gui::ParticleSystem::update_particle(float time_delta)
{
    for (auto &particle : particles) {
        if (particle.y > 7.0f) {
            particle.y = 0.0f;
            particle.z = (std::rand() % 10 - 5) / 2.0f;
            particle.x = (std::rand() % 10 - 5) / 2.0f;
        } else {
            particle.y += 0.3f * (time_delta * 50);
            particle.x *= 0.95f;
            particle.z *= 0.95f;
        }
    }
}

void Gui::ParticleSystem::draw(Texture2D texture, Camera3D camera)
{
    for (auto &particle : particles) {
        // std::cout << "draw particle" << std::endl;
        DrawBillboard(camera, texture, (Vector3){pos.x * SCALE + particle.x, particle.y, pos.y * SCALE + particle.z}, 3.0f, WHITE);
    }
}