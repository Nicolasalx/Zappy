/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** renderParticle
*/

#ifndef RENDERPARTICLE_H_
    #define RENDERPARTICLE_H_

    #include <raylib.h>
    #include <vector>
    #include "InfoGame.hpp"
    #include "GameData.hpp"
    #include "ARayLibModel.hpp"

namespace Gui
{
    struct ParticlePos {
        float x;
        float y;
        float z;
    };

    class RenderParticle
    {
        public:
            RenderParticle();
            ~RenderParticle() = default;

            void updateParticle(float time_delta);
            void draw(Texture2D texture, Camera3D camera);

            Pos pos;
            std::vector<ParticlePos> particles;
            size_t max_particles;

        private:
    };

    class RenderParticleSystem
    {
        public:
            RenderParticleSystem();
            ~RenderParticleSystem() = default;
            void updateParticleList(const GameData &gameData);
            void render(const GameData &gameData, Camera3D camera);

            Texture2D _particleTexture;
            std::vector<RenderParticle> _particleSystems;
    };
}

#endif /* !RENDERPARTICLE_H_ */
