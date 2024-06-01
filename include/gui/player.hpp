/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <vector>
    #include <string>
    #include "infoGame.hpp"
    #include "gameState.hpp"
    #include <map>

namespace Gui
{
    class Player {
        public:
            Player(std::vector<Model> &modelList, std::shared_ptr<GameState> gameState);
            ~Player() = default;

            ModelAnimation *player_animation;
            std::map<int, int> player_orientation;

        private:
            std::shared_ptr<GameState> _gameState;

    };
}

#endif /* !PLAYER_H_ */
