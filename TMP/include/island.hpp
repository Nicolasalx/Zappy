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
    class Island : public virtual IRaylib {
        public:
            Island(std::shared_ptr<GameState> gameState);
            ~Island() = default;

            void drawMap(ray_info_t &rayInfo);
            void render() {};

            float size;
        private:
            std::shared_ptr<GameState> _gameState;
    };
}

#endif /* !ISLAND_H_ */
