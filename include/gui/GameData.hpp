/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** GameData
*/

#ifndef GAMEDATA_HPP_
    #define GAMEDATA_HPP_

    #include "InfoGame.hpp"
    #include "RenderColor.hpp"

namespace Gui
{
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
        QUIT
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

    struct GameData
    {
        Pos mapSize;
        int timeUnit;
        int windowX;
        int windowY;
        double frameTime;
        std::vector<PlayerData> playerList;
        std::vector<Incant> incantList;
        std::vector<EggData> eggList;
        std::vector<std::string> teamName;
        std::vector<std::string> serverResp;
        std::vector<std::vector<std::vector<int>>> objectPos;
        std::vector<TextBoxData> textBox;
        Pos mousePos;
        DataMenu dataMenu;
    };
}

#endif /* !GAMEDATA_HPP_ */
