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

            Camera3D _camera;
            bool cursor = false;
            bool isPlayerMode = false;
            Pos playerPos;
        private:
    };
}

#endif /* !RENDERCAMERA_H_ */
