/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class Menu
    {
        public:
            Menu(std::shared_ptr<Gui::GameData> gameData);
            ~Menu() = default;

            void update(const Gui::Event &event);

        private:
            std::shared_ptr<Gui::GameData> _gameData;

    };
}

#endif /* !MENU_H_ */
