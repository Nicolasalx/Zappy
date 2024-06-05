/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "menu.hpp"

void Gui::Menu::componentPlay()
{
    addBox({InfoBox(0.4, 0.2, 0.3, 0.2, this->window_width, this->window_height)}, LIGHTGRAY);
    addText(Text("PLAY", { 0.4, 0.4 }, 20, LIGHTGRAY));

    addComponent(PLAY);
}

void Gui::Menu::componentSettings()
{
    addBox({InfoBox(0.4, 0.4, 0.3, 0.2, this->window_width, this->window_height )}, LIGHTGRAY);
    addText(Text("SETTINGS", { 0.4, 0.4 }, 20, LIGHTGRAY));

    addComponent(SETTINGS);
}

void Gui::Menu::componentQuit()
{
    addBox({InfoBox(0.4, 0.6, 0.3, 0.2, this->window_width, this->window_height)}, LIGHTGRAY);
    addText(Text("QUIT", { 0.4, 0.6 }, 20, LIGHTGRAY));


    addComponent(QUIT);
}

Gui::Menu::Menu(std::shared_ptr<GameState> gameState, int window_width, int window_height) : _gameState(gameState), window_width(window_width), window_height(window_height)
{
    componentPlay();
    componentSettings();
    componentQuit();
    resizeMenu(window_width, window_height);
}
