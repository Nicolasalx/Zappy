/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Player
*/

#ifndef RAYLIB_H_
    #define RAYLIB_H_

    #include "ARenderModule.hpp"
    #include "RenderWindow.hpp"
    #include "RenderSkyBox.hpp"
    #include "RenderEgg.hpp"
    #include "RenderObject.hpp"
    #include "RenderPlayer.hpp"
    #include "RenderCamera.hpp"
    #include "RenderMenu.hpp"
    #include "RenderIsland.hpp"
    #include "RenderParticle.hpp"
    #include "RenderTextBox.hpp"
    #include <raylib.h>
    #include <iostream>

namespace Gui
{
    class Raylib : public ARenderModule
    {
        public:
            Raylib();
            ~Raylib() override;
 
            Gui::Event getEvent() override;
            void render(const Gui::GameData &gameData) override;
            void renderGame(const Gui::GameData &gameData);

        private:
            Gui::RenderWindow window;
            Gui::RenderCamera camera;
            std::unique_ptr<Gui::RenderSkyBox> skyBox;
            std::unique_ptr<Gui::RenderIsland> island;
            std::unique_ptr<Gui::RenderObject> object;
            std::unique_ptr<Gui::RenderPlayer> player;
            std::unique_ptr<Gui::RenderParticleSystem> particle;
            std::unique_ptr<Gui::RenderEgg> egg;
            std::unique_ptr<Gui::RenderTextBoxList> textBoxList;
            Gui::RenderMenu menu;
    };
}

#endif /* !RAYLIB_H_ */
