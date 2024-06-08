/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** RenderCamera
*/

#ifndef RENDERCAMERA_H_
    #define RENDERCAMERA_H_

    #include "GameData.hpp"
    #include <raylib.h>

namespace Gui {
    class RenderCamera
    {
        public:
            RenderCamera();
            ~RenderCamera() = default;

            Camera3D _camera;
        private:
    };
}

#endif /* !RENDERCAMERA_H_ */
