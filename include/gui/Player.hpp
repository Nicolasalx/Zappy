/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "Zappy.hpp"

namespace Gui
{
    class Player: public Gui::Zappy
    {
        public:
            Player();
            ~Player() override;
    
            const Gui::GameData &update(const Gui::Event &event) override;
    
        private:
    
    };
}

#endif /* !PLAYER_H_ */
