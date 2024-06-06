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
    class Particle: public Gui::Zappy
    {
        public:
            Particle();
            ~Particle() override;

            const Gui::GameData &update(const Gui::Event &event) override;
    
        private:
    
    };
}

#endif /* !PARTICLE_H_ */
