/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** island
*/

#ifndef RENDERISLAND_H_
    #define RENDERISLAND_H_

    #include <vector>
    #include <memory>
    #include "GameData.hpp"
    #include "RenderRayInfo.hpp"

namespace Gui
{
    class RenderIsland : public virtual Gui::ARayLibModel
    {
        public:
            RenderIsland();
            ~RenderIsland() = default;

            void render(const Gui::GameData &gameData);

        private:
            BoundingBox _box;
    };
}

#endif /* !RENDERISLAND_H_ */
