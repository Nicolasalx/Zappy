/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** GameData
*/

#ifndef GAMEDATA_HPP_
    #define GAMEDATA_HPP_

    #include "InfoGame.hpp"

namespace Gui
{
    struct GameData
    {
        Pos mapSize;
        int timeUnit;
        int windowX;
        int windowY;
        double frameTime;
        std::vector<Pos> islandInfo;
        std::vector<PlayerData> playerList;
        std::vector<Incant> incantList;
        std::vector<EggData> eggList;
        std::vector<std::string> teamName;
        std::vector<std::string> serverResp;
        std::vector<std::vector<std::vector<int>>> objectPos;
        std::vector<TextBoxData> textBox;
        Pos playerPos;
        RayInfoData rayInfo;
        DataMenu dataMenu;
        InfoWindow infoWindow;
        bool ignoreKey;
    };
}

#endif /* !GAMEDATA_HPP_ */
