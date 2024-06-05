/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "menu.hpp"

void Gui::Menu::componentPlay()
{
    addBox({InfoBox(window_width / 2.0f - 100, window_height / 2.0f - 250, 200, 100 )}, LIGHTGRAY);
    addText(Text("PLAY", { window_width / 2.0f - 100, window_height / 2.0f - 250 }, 20, LIGHTGRAY));

    addComponent(PLAY);
}

void Gui::Menu::componentSettings()
{
    addBox({InfoBox(window_width / 2.0f - 100, window_height / 2.0f - 50, 200, 100 )}, LIGHTGRAY);
    addText(Text("SETTINGS", { window_width / 2.0f - 100, window_height / 2.0f - 50 }, 20, LIGHTGRAY));

    addComponent(SETTINGS);
}

void Gui::Menu::componentQuit()
{
    addBox({InfoBox(window_width / 2.0f - 100, window_height / 2.0f + 150, 200, 100 )}, LIGHTGRAY);
    addText(Text("QUIT", { window_width / 2.0f - 100, window_height / 2.0f + 150 }, 20, LIGHTGRAY));

    addComponent(QUIT);
}

Gui::Menu::Menu(std::shared_ptr<GameState> gameState, int window_width, int window_height) : _gameState(gameState), window_width(window_width), window_height(window_height)
{
    componentPlay();
    componentSettings();
    componentQuit();
}
