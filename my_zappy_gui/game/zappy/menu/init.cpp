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
    addBox({Box(0.1, 0.5, 0.4, 0.1, BLUE_COLOR)}, "PLAY");
    addComponent(PLAY);
}

void Gui::Menu::componentSettings()
{
    addBox({Box(0.1, 0.7, 0.4, 0.1, BLUE_COLOR)}, "SETTINGS");
    addComponent(SETTINGS);
}

void Gui::Menu::componentQuit()
{
    addBox({Box(0.1, 0.9, 0.4, 0.1, BLUE_COLOR)}, "QUIT");
    addComponent(QUIT);
}

void Gui::Menu::componentPlayerMode()
{
    addBox({Box(0.1, 0.1, 0.4, 0.1, BLUE_COLOR)}, "PLAYER MODE");
    addComponent(PLAYER_MODE);
}

void Gui::Menu::componentSpectatorMode()
{
    addBox({Box(0.1, 0.3, 0.4, 0.1, BLUE_COLOR)}, "SPECTATOR MODE");
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
