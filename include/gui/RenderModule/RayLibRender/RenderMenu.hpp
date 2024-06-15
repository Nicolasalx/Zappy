/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** RenderMenu
*/

#ifndef RENDERMENU_H_
    #define RENDERMENU_H_

    #include "GameData.hpp"
    #include <raylib.h>
    #include "RenderWindow.hpp"

namespace Gui {
    class RenderMenu
    {
        public:
            RenderMenu();
            ~RenderMenu() = default;
            void render(const GameData &gameData, Gui::RenderWindow &window);
            void renderOneComponent(const Gui::Component &component);

            StateGame stateGame;
            bool needToResize = false;
        private:
            int _windowWidth = 0;
            int _windowHeight = 0;
    };
}

#endif /* !RENDERMENU_H_ */
