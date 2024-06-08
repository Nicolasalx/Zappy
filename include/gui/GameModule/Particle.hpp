/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Particle
*/

#ifndef PARTICLE_HPP_
    #define PARTICLE_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class Particle
    {
        public:
            Particle(std::shared_ptr<Gui::GameData> gameData);
            ~Particle() = default;

            void update(const Gui::Event &event);

        private:
            std::shared_ptr<Gui::GameData> _gameData;

    };
}

#endif /* !PARTICLE_H_ */
