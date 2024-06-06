/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Island
*/

#ifndef ISLAND_HPP_
    #define ISLAND_HPP_

    #include "Zappy.hpp"

namespace Gui
{
    class Island: public Gui::Zappy
    {
        public:
            Island();
            ~Island() override;
    
            const Gui::GameData &update(const Gui::Event &event) override;
    
        private:
    
    };
}

#endif /* !ISLAND_H_ */
