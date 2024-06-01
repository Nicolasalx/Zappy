/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** infoGame
*/

#ifndef INFOGAME_H_
    #define INFOGAME_H_

    #include <iostream>
    #include <raylib.h>

namespace Gui
{
    constexpr float MAP_SCALE = 6.0f;
    constexpr float WINDOW_WIDTH = 1920 / 2;
    constexpr float WINDOW_HEIGHT = 1080 / 2;

    struct pos_t {
        float x;
        float y;
    };

    enum {
        FOOD,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME,
        ISLAND,
        PLAYER
    };
    
    enum {
        NO_BUTTON,
        RIGHT_BUTTON,
        LEFT_BUTTON,
        CLOSED_LEFT,
        CLOSED_RIGHT
    };

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
}

#endif /* !INFOGAME_H_ */
