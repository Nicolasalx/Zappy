/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** RenderCamera
*/

#ifndef RENDERCAMERA_H_
    #define RENDERCAMERA_H_

    #include "ARayLibModel.hpp"
    #include "GameData.hpp"
    #include "Event.hpp"
    #include <raylib.h>

namespace Gui {
    class RenderCamera
    {
        public:
            RenderCamera();
            ~RenderCamera() = default;

            void render(const GameData &gameData);
            void update(int state);
            void handle_cursor();
            void updatePlayerPos(Gui::Event &event);
            void playerMode();
            void spectatorMode();
            void spectatorTopMode();
            void changeSpectatorMode();
            void endGameMode();
            void setPlayerEndGamePos(float x, float y, float z);

            Camera3D _camera;
            bool cursor = true;
            bool topViewMode = false;
            Pos playerPos;
            Pos map_dimension;
            float _x = 0;
            float _y = 0;
            float _z = 0;
        private:
    };
}

#endif /* !RENDERCAMERA_H_ */
