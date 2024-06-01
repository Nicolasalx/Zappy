/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** object
*/

#ifndef OBJECT_H_
    #define OBJECT_H_

    #include "raylibInfo.hpp"
    #include <vector>
    #include <memory>

namespace Gui
{
    class Object
    {
        public:
            Object(std::shared_ptr<GameState> gameState);
            ~Object() = default;

            float object_padding[7][2];

            void render();

            std::vector<Model> _modelList;

        private:
            std::shared_ptr<GameState> _gameState;

    };
}

#endif /* !OBJECT_H_ */
