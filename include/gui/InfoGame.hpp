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
    #include <functional>

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

    enum GameColor {
        WHITE_COLOR,
        BLACK_COLOR,
        BLUE_COLOR,
        GREEN_COLOR,
        RED_COLOR,
        GRAY_COLOR,
        PURPLE_COLOR
    };

    struct Box {
        float x;
        float y;
        float width;
        float height;
        GameColor color;
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

    struct Text {
        std::string contentText;
        Pos pos;
        Pos realPos;
        double fontSize;
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
        INPUT_PORT,
        INPUT_TEAM_NAME,
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

    enum SizeButton {
        BIG,
        MIDDLE,
        LITTLE
    };

    enum StateFrequency {
        NOT_SEND,
        SEND_DATA,
        GET_DATA
    };

    enum CursorState {
        DEFAULT,
        SELECTIONNED
    };

    enum OptionResolution {
        FULLSCREEN,
        WINDOWED
    };

    struct DataResolution {
        std::string resText;
        OptionResolution windowSize;
    };

    struct Component {
        Box box;
        Text text;
        SettingsComponent settingsComponent;
        StockStartData stockStartData;
        ComponentType componentType;
    };

    enum InputSelectionned {
        NO,
        IP,
        PORT,
        TEAM_NAME
    };

    struct DataConnection {
        std::string ip;
        std::string port;
        std::string teamName;
    };

    struct DataMenu {
        StateGame stateGame = IN_MENU;
        std::vector<Gui::Component> componentList;
        CursorState cursorState;
        InputSelectionned inputSelect;
        std::vector<Text> componentsTitle;
        DataConnection dataConnection;
    };

    struct BoxOpt {
        Pos pos;
        Size size;

        Pos realPos;
        Size realSize;
        GameColor color;
    };

    struct InfoWindow {
        BoxOpt buttonNextDisplay;
        Text textButtonNextDisp;
        bool changeDisplayLib;

        OptionResolution resolution;
        int volume;
    };

    struct ButtonPlayerMode {
        BoxOpt button;
        Text text;

        std::function<void()> actPlayer;
    };

    struct DataPlayerMode {
        std::vector<ButtonPlayerMode> buttonPlayerMode;
    };

    struct InfoSlider {
        BoxOpt sliderBar;
        BoxOpt sliderHandle;
        int sliderValue;
    };
}

#endif /* !INFOGAME_H_ */
