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
    #include "InfoGame.hpp"

namespace Gui {
    class RenderMenu : public virtual Gui::ARayLibModel
    {
        public:
            RenderMenu();
            ~RenderMenu() = default;
            void render(const GameData &gameData) override;
            void renderOneComponent(const Gui::Component &component);
            void render3DModel(Camera3D camera);
            void renderMenu(const GameData &gameData, Camera3D camera);

            StateGame stateGame = IN_MENU;
            InputSelectionned inputSelect = NO;
            Texture2D menuIsland;
            Texture2D spaceTexture;
            Texture2D zappyLogo;
            bool needToClearBuffer = false;
        private:
            float earthRotation = 0;
            OptionResolution _optionResolution = WINDOWED;
    };
}

#endif /* !RENDERMENU_H_ */
