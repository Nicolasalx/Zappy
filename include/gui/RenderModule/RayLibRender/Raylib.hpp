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
    #include "RenderRayInfo.hpp"
    #include "RenderEndGame.hpp"
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
            void handleSoundSystem(const Gui::GameData &gameData);

            void getKeyEvent(Gui::Event &event);

            void putEventInBuffer(Gui::Event &event);
            void putEventInEventList(Gui::Event &event);

        private:
            std::vector<std::pair<KeyboardKey, Gui::EventType>> _keyBind = {
                {KEY_N, Gui::EventType::NEXT_DISPLAY},
                {KEY_M, Gui::EventType::BACK_MENU},
                {KEY_R, Gui::EventType::RESTART},
                {KEY_ENTER, Gui::EventType::ENTER}
            };

            KeyboardKey _eventKeyBoard;
            Gui::Event _event;

            Gui::RenderWindow window;
            Gui::RenderCamera camera;
            std::unique_ptr<Gui::RenderSkyBox> skyBox;
            std::unique_ptr<Gui::RenderIsland> island;
            std::unique_ptr<Gui::RenderObject> object;
            std::unique_ptr<Gui::RenderPlayer> player;
            std::unique_ptr<Gui::RenderParticleSystem> particle;
            std::unique_ptr<Gui::RenderEgg> egg;
            std::unique_ptr<Gui::RenderTextBoxList> textBoxList;
            std::unique_ptr<Gui::RenderRayInfo> rayInfo;
            std::unique_ptr<Gui::RenderEndGame> endGame;
            Gui::RenderMenu menu;
    };
}

#endif /* !RAYLIB_H_ */
