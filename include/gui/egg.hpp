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

namespace Gui {
    class Egg {
        public:
            Egg(std::shared_ptr<GameState> gameState);
            ~Egg() = default;
            void draw();
            std::vector<egg_t> eggs_list;
        private:
            Model _egg_model;
            Texture2D _egg_texture;
            std::shared_ptr<GameState> _gameState;
    };
}

#endif /* !EGG_H_ */