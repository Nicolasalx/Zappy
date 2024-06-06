/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** InfoGame
*/

#ifndef INFOGAME_H_
    #define INFOGAME_H_

    #include <iostream>
    #include <vector>

namespace Gui
{
    constexpr float MAP_SCALE = 12.0f;
    constexpr float WINDOW_WIDTH = 1920 / 2;
    constexpr float WINDOW_HEIGHT = 1080 / 2;

    struct Pos {
        float x;
        float y;
    };

    enum Elements {
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

    enum StateBox {
        NO_BUTTON,
        RIGHT_BUTTON,
        LEFT_BUTTON,
        CLOSED_LEFT,
        CLOSED_RIGHT
    };

    struct TextBox {
        std::string text;
        Pos pos;
        float width;
        float height;
        int text_size;
        int state;
    };

    struct Incant {
        int level;
        Pos pos;
    };

    struct Egg {
        int player_number;
        int egg_number;
        Pos pos;
    };

    struct Player {
        int n;
        Pos pos;
        Pos real_pos;
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
