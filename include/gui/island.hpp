/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** island
*/

#ifndef ISLAND_H_
    #define ISLAND_H_

    #include <vector>

namespace Gui
{
    class Island {
        public:
            Island(std::shared_ptr<GameState> gameState);
            ~Island() = default;

            void drawMap(ray_info_t &rayInfo);

            Model island_model;
            Texture2D island_texture;
        private:
            std::shared_ptr<GameState> _gameState;
    };
}

#endif /* !ISLAND_H_ */
