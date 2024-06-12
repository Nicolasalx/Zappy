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
    constexpr float MAP_SCALE = 12.0;
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

    struct TextBoxData {
        TextBoxData(float x, float y, float width, float height, float textSize, int state);
        Pos _pos;
        Pos _size;
        Pos _real_pos;
        Pos _real_size;
        Pos _buttonPos;
        Pos _buttonSize;
        float _text_size;
        int _state;
        std::vector<std::string> _text;
    };

    struct Incant {
        int level;
        Pos pos;
    };

    struct EggData {
        int player_number;
        int egg_number;
        Pos pos;
    };

    struct PlayerData {
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

    enum GameColor {
        WHITE_COLOR,
        BLACK_COLOR,
        BLUE_COLOR,
        GREEN_COLOR,
        RED_COLOR,
        GRAY_COLOR,
        PURPLE_COLOR
    };

    struct Text {
        std::string contentText;
        Pos pos;
        int fontSize;
        GameColor color;
    };

    struct Box {
        float x;
        float y;
        float width;
        float height;
        GameColor color;
    };

    struct StockStartData {
        Box box;
        Text text;
    };

    enum ComponentType {
        NONE,
        PLAY,
        SETTINGS,
        QUIT,
        PLAYER_MODE,
        SPECTATOR_MODE
    };

    struct Component {
        Box box;
        Text text;
        StockStartData stockStartData;
        ComponentType componentType;
    };

    struct DataMenu {
        bool gameIsLaunch;
        std::vector<Gui::Component> componentList;
    };

    struct WindowSize {
        float width;
        float height;
    };
}

#endif /* !INFOGAME_H_ */
