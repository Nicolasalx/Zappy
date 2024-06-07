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
    #include "RayLibObject.hpp"
    #include <map>

namespace Gui
{
    class RenderPlayer : public virtual RaylibObject {
        public:
            Player();
            ~Player() = default;
            void updateAnimation(player_t &player);
            void updatePlayerPos(player_t &player);
            void drawPlayer(ray_info_t &rayInfo);
            void drawPlayerModel(player_t &player);
            void drawPlayerBox(ray_info_t &rayinfo, player_t &player);
            void render() {};

            ModelAnimation *player_animation;
            std::map<int, int> player_orientation;
            std::map<int, Color> player_color;
        private:

    };
}

#endif /* !PLAYER_H_ */
