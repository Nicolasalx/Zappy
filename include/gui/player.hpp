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

namespace Gui
{
    struct player_t {
        int n;
        Gui::pos_t pos;
        Gui::pos_t real_pos;
        int level;
        int orientation;
        int real_orientation;
        std::string team_name;
        std::vector<int> inventory;
        int animation_nbr;
        int anim_frame_counter;
    };

    class Player {
        public:
            Player(std::vector<Model> &modelList);
            ~Player() = default;

            ModelAnimation *player_animation;

        private:
    };
}

#endif /* !PLAYER_H_ */
