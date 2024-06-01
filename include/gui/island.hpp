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
            Island(std::vector<Model> &modelList, std::shared_ptr<GameState> gameState);
            ~Island() = default;

        private:
            std::shared_ptr<GameState> _gameState;

    };
}

#endif /* !ISLAND_H_ */
