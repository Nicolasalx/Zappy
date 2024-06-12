/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initMenu
*/

#include "Menu.hpp"
#include "GameConfig.hpp"

void Gui::Menu::componentPlay()
{
    addBox({Box(0.4, 0.1, 0.2, 0.1, BLUE_COLOR)});
    addText(Text("PLAY", { 0.4, 0.4 }, sizeFontTextMenu, BLUE_COLOR));

    addComponent(PLAY);
}

void Gui::Menu::componentSettings()
{
    addBox({Box(0.4, 0.3, 0.2, 0.1, BLUE_COLOR)});
    addText(Text("SETTINGS", { 0.4, 0.7 }, sizeFontTextMenu, BLUE_COLOR));

    addComponent(SETTINGS);
}

void Gui::Menu::componentQuit()
{
    addBox({Box(0.4, 0.5, 0.2, 0.1, BLUE_COLOR)});
    addText(Text("QUIT", { 0.4, 0.7 }, sizeFontTextMenu, BLUE_COLOR));

    addComponent(QUIT);
}

void Gui::Menu::componentPlayerMode()
{
    addBox({Box(0.4, 0.7, 0.2, 0.1, BLUE_COLOR)});
    addText(Text("PLAYER MODE", { 0.4, 0.7 }, sizeFontTextMenu, BLUE_COLOR));

    addComponent(PLAYER_MODE);
}

void Gui::Menu::componentSpectatorMode()
{
    addBox({Box(0.4, 0.9, 0.2, 0.1, BLUE_COLOR)});
    addText(Text("SPECTATOR MODE", { 0.4, 0.7 }, sizeFontTextMenu, BLUE_COLOR));

    addComponent(SPECTATOR_MODE);
}

Gui::Menu::Menu(std::shared_ptr<Gui::GameData> gameData): _gameData(gameData)
{
    componentPlay();
    componentSettings();
    componentPlayerMode();
    componentSpectatorMode();
    componentQuit();
}
