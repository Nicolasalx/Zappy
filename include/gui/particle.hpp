/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** particle
*/

#ifndef PARTICLE_HPP_
    #define PARTICLE_HPP_
    #include "infoGame.hpp"
    #include <list>
    #include <raylib.h>
    #include <iostream>

namespace Gui
{
    struct particle_pos_t {
        float x;
        float y;
        float z;
    };

    class Particle {
        public:
            Particle();
            ~Particle() = default;
            void update_particle(float time_delta);
            void draw(Texture2D texture, Camera3D camera);

            pos_t pos;
            std::vector<particle_pos_t> particles;
            size_t max_particles;
            
    };

    class ParticleSystem {
        public:
            ParticleSystem(std::shared_ptr<GameState> gameState);
            ~ParticleSystem() = default;
            void update_particle_list();
            void draw_particle(Camera3D camera);

            Texture2D particle_texture;
            std::vector<Particle> particle_systems;
            std::shared_ptr<GameState> _gameState;
    };
}

#endif