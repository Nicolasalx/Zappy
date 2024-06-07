/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "Zappy.hpp"

namespace Gui
{
    class Menu: public Gui::Zappy
    {
        public:
            Menu();
            ~Menu() override;

            const Gui::GameData &update(const Gui::Event &event) override;

        private:

    };
}

#endif /* !MENU_H_ */
