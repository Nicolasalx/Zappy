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
    class Menu
    {
        public:
            Menu();
            ~Menu();

            const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event);

        private:

    };
}

#endif /* !MENU_H_ */
