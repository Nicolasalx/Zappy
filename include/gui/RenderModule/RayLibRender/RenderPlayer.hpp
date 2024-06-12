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
            void updateAnimation(const PlayerData &player);
            void drawPlayerModel(const PlayerData &player);
            void drawPlayerBox(const Gui::PlayerData &player);
            void render(const GameData &gameData);

            ModelAnimation *player_animation;
            BoundingBox player_box;
            std::map<int, int> player_orientation;
            std::map<int, Color> player_color;
        private:

    };
}

#endif /* !RENDERPLAYER_H_ */
