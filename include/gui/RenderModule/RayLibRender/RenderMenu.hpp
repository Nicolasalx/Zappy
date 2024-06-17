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
    #include "ARayLibModel.hpp"

namespace Gui {
    class RenderMenu : public virtual Gui::ARayLibModel
    {
        public:
            RenderMenu();
            ~RenderMenu() = default;
            void render(const GameData &gameData);
            void renderOneComponent(const Gui::Component &component);
            void render3DModel(Camera3D camera);
            void renderMenu(const GameData &gameData, Camera3D camera);

            StateGame stateGame = IN_MENU;
            bool needToResize = false;
            Texture2D menuIsland;
        private:
            int _windowWidth = 0;
            int _windowHeight = 0;
            float earthRotation = 0;
    };
}

#endif /* !RENDERMENU_H_ */
