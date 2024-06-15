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
    constexpr float MAP_SCALE =  120.0;
    constexpr float WINDOW_WIDTH = 1920;
    constexpr float WINDOW_HEIGHT = 1080;
    constexpr float ISLAND_SIZE = 70.0;

    struct Pos {
        float x;
        float y;
    };

    struct Size {
        float width;
        float height;
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
        CLOSED_RIGHT,
        NOT_SHOWN
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

    struct RayInfoData {
        int type = 0;
        int id = 0;
        int x = 0;
        int y = 0;
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
        double fontSize;
        GameColor color;
    };

    struct Box {
        float x;
        float y;
        float width;
        float height;
        GameColor color;
    };

    struct Triangle {
        Pos topVertex;
        Pos bottomLeftVertex;
        Pos bottomRightVertex;
        GameColor color;
    };

    struct SettingsComponent {
        Triangle triangleLeft;
        Triangle triangleRight;
    };

    struct StockStartData {
        Box box;
        Text text;
        SettingsComponent settingsComponent;
    };

    enum ComponentType {
        NONE,
        SETTINGS,
        QUIT,
        PLAYER_MODE,
        SPECTATOR_MODE,
        INPUT_BOX_IP,
        ANNOUNCE_RETRY,
        GO_BACK_TO_MENU,
        MODIFY_SETTINGS,
        MODIFY_RESOLUTION,
        MODIFY_VOLUME
    };

    enum StateGame {
        IN_PLAYER_MODE,
        TRY_PLAYER_MODE,
        IN_SPECTATOR_MODE,
        TRY_SPECTATOR_MODE,
        CONNECTION_FAILED_MENU,
        IN_SETTINGS,
        IN_MENU,
        IN_LEAVE
    };

    enum CursorState {
        DEFAULT,
        SELECTIONNED
    };

    struct OptionResolution {
        std::string resText;
        Size windowSize;
    };

    struct Component {
        Box box;
        Text text;
        SettingsComponent settingsComponent;
        StockStartData stockStartData;
        ComponentType componentType;
    };

    struct DataMenu {
        StateGame stateGame = IN_MENU;
        std::vector<Gui::Component> componentList;
        CursorState cursorState;
    };

    struct InfoWindow {
        Size resolution;
        int volume;
    };
}

#endif /* !INFOGAME_H_ */
