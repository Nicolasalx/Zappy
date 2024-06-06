/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Zappy
*/

#ifndef ZAPPY_HPP_
    #define ZAPPY_HPP_

    #include "AGameModule.hpp"

namespace Gui
{
    class Zappy: public Gui::AGameModule
    {
        public:
            Zappy();
            ~Zappy() override;

            const Gui::GameData &update(const Gui::Event &event) override;

        private:
    
    };
};

#endif /* !ZAPPY_HPP_ */
