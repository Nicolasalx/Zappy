/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initMenu
*/

#include "Menu.hpp"

void Gui::Menu::componentPlay()
{
    addBox({Box(0.4, 0.2, 0.3, 0.2, BLUE_COLOR)});
    addText(Text("PLAY", { 0.4, 0.4 }, 20, BLUE_COLOR));

    addComponent(PLAY);
}

void Gui::Menu::componentSettings()
{
    addBox({Box(0.4, 0.5, 0.3, 0.2, BLUE_COLOR)});
    addText(Text("SETTINGS", { 0.4, 0.7 }, 20, BLUE_COLOR));

    addComponent(SETTINGS);
}

Gui::Menu::Menu(std::shared_ptr<Gui::GameData> gameData): _gameData(gameData)
{
    componentPlay();
    componentSettings();
}
