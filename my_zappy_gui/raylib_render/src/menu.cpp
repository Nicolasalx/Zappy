/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "RenderMenu.hpp"
#include "RenderWindow.hpp"
#include "RenderColor.hpp"
#include "GameConfig.hpp"

Gui::RenderMenu::RenderMenu()
{
    this->addModel(Gui::MENU_MARS_MODEL.data());
}

void Gui::RenderMenu::renderOneComponent(const Gui::Component &component)
{
    DrawRectangleLinesEx((Rectangle) {component.box.x, component.box.y, component.box.width, component.box.height}, 3, Gui::RenderColor::getColorFromGame(component.box.color));
    DrawText(component.text.contentText.c_str(), component.box.x, component.box.y, 20, Gui::RenderColor::getColorFromGame(component.box.color));
}

void Gui::RenderMenu::render(const GameData &gameData)
{
    ClearBackground(LIGHTGRAY);

    for (auto &item: gameData.dataMenu.componentList) {
        renderOneComponent(item);
    }

    this->drawModel((Gui::ModelInfo){0,
        {0, 0, 0},
        {0, 0, 0},
        0,
        {1, 1, 1},
        WHITE}
    );
}
