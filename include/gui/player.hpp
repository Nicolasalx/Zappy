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
            Player(std::shared_ptr<GameState> gameState);
            ~Player() = default;
            void update_animation(player_t &player);
            void update_player_pos(player_t &player);
            void draw_player(ray_info_t &rayInfo);
            void draw_player_model(player_t &player);
            void draw_player_box(ray_info_t &rayinfo, player_t &player);

            ModelAnimation *player_animation;
            std::map<int, int> player_orientation;
            Model player_model;
            Texture2D player_texture;

        private:
            std::shared_ptr<GameState> _gameState;

    };
}

#endif /* !PLAYER_H_ */
