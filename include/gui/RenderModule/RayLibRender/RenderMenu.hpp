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

namespace Gui {
    class RenderMenu
    {
        public:
            RenderMenu();
            ~RenderMenu() = default;
            void render(const GameData &gameData);
            void renderOneComponent(Component &component);
            void resize(int window_width, int window_height);
            void initMenu(const GameData &gameData);

        private:
            int _windowWidth = 0;
            int _windowHeight = 0;
            std::vector<Gui::Component> _componentList;
    };
}

#endif /* !RENDERMENU_H_ */
