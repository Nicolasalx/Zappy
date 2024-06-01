/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <vector>

namespace Gui
{
    class Menu {
        public:
            Menu(std::shared_ptr<GameState> gameState);
            ~Menu() = default;

            bool isInMenu = false;

        private:
            std::shared_ptr<GameState> _gameState;

    };
}

#endif /* !MENU_H_ */
