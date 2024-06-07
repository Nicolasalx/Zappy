/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

    #include "gameState.hpp"
    #include "infoGame.hpp"
    #include <vector>
    #include <memory>
    #include "raylibInfo.hpp"

namespace Gui {
    class RenderEgg
    {
        public:
            RenderEgg(std::shared_ptr<GameState> gameState);
            ~RenderEgg() = default;
            void render();

            std::vector<egg_t> eggs_list;
        private:
            std::shared_ptr<GameState> _gameState;
    };
}

#endif /* !EGG_H_ */