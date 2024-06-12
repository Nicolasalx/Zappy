/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player
*/

#ifndef RENDERRAYINFO_H_
    #define RENDERRAYINFO_H_

    #include <raylib.h>
    #include "Event.hpp"
    #include "GameData.hpp"
    #include "InfoGame.hpp"

namespace Gui 
{
    class RenderRayInfo {
        public:
            RenderRayInfo();
            ~RenderRayInfo() = default;
            void selectEvent(const GameData &gameData, Camera3D camera);
            void changePlayerSelected(const GameData &gameData);
            void addRayToEvent(Gui::Event &event);
            void render(const GameData &gameData, Camera3D camera);
            Ray ray;
            BoundingBox box;
            RayCollision collision;
            RayInfoData rayInfo;
    };
}

#endif /* !RENDERRAYINFO_H_ */