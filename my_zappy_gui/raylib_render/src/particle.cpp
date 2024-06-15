/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** particle
*/

#include "RenderParticle.hpp"
#include "GameConfig.hpp"
#include "RenderIsland.hpp"

Gui::RenderParticle::RenderParticle()
{
    this->max_particles = 20;
    for (size_t i = 0; i < this->max_particles; i++) {
        ParticlePos new_particle;
        new_particle.x = (std::rand() % 10 - 5) / 2.0;
        new_particle.y = std::rand() % 7;
        new_particle.z = (std::rand() % 10 - 5) / 2.0;
        particles.push_back(new_particle);
    }
}

Gui::RenderParticleSystem::RenderParticleSystem()
{
    this->_particleTexture = LoadTexture(Gui::EVOLUTION_TEXTURE.data());
}

void Gui::RenderParticleSystem::updateParticleList(const GameData &gameData)
{
    while (this->_particleSystems.size() != gameData.incantList.size()) {
        if (this->_particleSystems.size() < gameData.incantList.size()) {
            this->_particleSystems.push_back(RenderParticle());
        } else {
            this->_particleSystems.pop_back();
        }
        for (size_t i = 0; i < gameData.incantList.size() && i < _particleSystems.size(); i++) {
            this->_particleSystems[i].pos.x = gameData.incantList[i].pos.x;
            this->_particleSystems[i].pos.y = gameData.incantList[i].pos.y;
        }
    }
}

void Gui::RenderParticle::updateParticle(float time_delta)
{
    for (auto &particle : particles) {
        if (particle.y > 7.0) {
            particle.y = 0.0;
            particle.z = (std::rand() % 10 - 5) / 2.0;
            particle.x = (std::rand() % 10 - 5) / 2.0;
        } else {
            particle.y += 0.3f * (time_delta * 50);
            particle.x *= 0.95f;
            particle.z *= 0.95f;
        }
    }
}

void Gui::RenderParticle::draw(Texture2D texture, Camera3D camera)
{
    for (auto &particle: particles) {
        DrawBillboard(camera, texture, (Vector3){pos.x * Gui::RenderIsland::map_scale + particle.x, particle.y, pos.y * Gui::RenderIsland::map_scale + particle.z}, 3.0, WHITE);
    }
}

void Gui::RenderParticleSystem::render(const GameData &gameData, Camera3D camera)
{
    updateParticleList(gameData);
    for (auto &particle_system : this->_particleSystems) {
        particle_system.updateParticle(gameData.frameTime);
        particle_system.draw(this->_particleTexture, camera);
    }
}
