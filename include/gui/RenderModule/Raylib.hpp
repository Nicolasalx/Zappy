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
    #include <raylib.h>
    #include <iostream>

namespace Gui {

    class Raylib : public ARenderModule
    {
        public:
            Raylib();
            ~Raylib() override;
 
            Gui::Event getEvent() override;
            void render(const Gui::GameData &gameData) override;

        private:
            Gui::Window window;
            Gui::Camera camera;
            std::unique_ptr<Gui::RenderSkyBox> skyBox;
            std::unique_ptr<Gui::RenderIsland> island;
            std::unique_ptr<Gui::RenderObject> object;
            std::unique_ptr<Gui::RenderPlayer> player;
            Gui::Menu menu;
            std::unique_ptr<Gui::RenderEgg> egg;
    };
}

#endif /* !RAYLIB_H_ */
