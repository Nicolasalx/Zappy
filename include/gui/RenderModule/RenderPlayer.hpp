/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player
*/

#ifndef RENDERPLAYER_H_
    #define RENDERPLAYER_H_

    #include <vector>
    #include <string>
    #include "ARayLibModel.hpp"
    #include <map>

namespace Gui
{
    class RenderPlayer : public virtual ARayLibModel
    {
        public:
            RenderPlayer();
            ~RenderPlayer() = default;
            // void updateAnimation(Player &player);
            // void updatePlayerPos(Player &player);
            // void drawPlayer(rayInfo &rayInfo);
            void drawPlayerModel(const Player &player);
            // void drawPlayerBox(rayinfo &rayinfo, Player &player);
            void render(const GameData &gameData);

            ModelAnimation *player_animation;
            std::map<int, int> player_orientation;
            std::map<int, Color> player_color;
        private:

    };
}

#endif /* !RENDERPLAYER_H_ */
