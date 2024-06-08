/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Particle
*/

#ifndef PARTICLE_HPP_
    #define PARTICLE_HPP_

    #include "Zappy.hpp"

namespace Gui
{
    class Particle
    {
        public:
            Particle();
            ~Particle();

            const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event);

        private:

    };
}

#endif /* !PARTICLE_H_ */
