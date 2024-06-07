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

namespace Gui
{
    class RenderIsland
    {
        public:
            RenderIsland();
            ~RenderIsland() = default;

            void drawMap(rayInfo &rayInfo);
            void render(const GameData &gameData);

            float size;
        private:
            // std::shared_ptr<GameState> _gameState;
    };
}

#endif /* !RENDERISLAND_H_ */
