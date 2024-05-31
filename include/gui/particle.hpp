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

    class ParticleSystem {
        public:
            ParticleSystem();
            ~ParticleSystem() = default;
            void update_particle();
            void draw(Texture2D texture, Camera3D camera);

            pos_t pos;
            std::list<particle_pos_t> particles;
            size_t max_particles;
    };
}
#endif