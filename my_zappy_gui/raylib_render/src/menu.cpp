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
    // this->addModel(Gui::MENU_MARS_MODEL.data());
}

void Gui::RenderMenu::renderOneComponent(const Gui::Component &component)
{
    DrawRectangleLinesEx((Rectangle) {component.box.x, component.box.y, component.box.width, component.box.height}, 3, Gui::RenderColor::getColorFromGame(component.box.color));
    DrawText(component.text.contentText.c_str(), component.text.pos.x, component.text.pos.y, component.text.fontSize, Gui::RenderColor::getColorFromGame(component.text.color));

    if (component.settingsComponent.triangleLeft.color > 6 || component.settingsComponent.triangleLeft.color < 0 ||
        component.settingsComponent.triangleRight.color > 6 || component.settingsComponent.triangleRight.color < 0) {
        return;
    }
    DrawTriangle(Vector2(component.settingsComponent.triangleLeft.topVertex.x, component.settingsComponent.triangleLeft.topVertex.y),
        Vector2(component.settingsComponent.triangleLeft.bottomLeftVertex.x, component.settingsComponent.triangleLeft.bottomLeftVertex.y),
        Vector2(component.settingsComponent.triangleLeft.bottomRightVertex.x, component.settingsComponent.triangleLeft.bottomRightVertex.y), Gui::RenderColor::getColorFromGame(component.settingsComponent.triangleLeft.color));
    DrawTriangle(Vector2(component.settingsComponent.triangleRight.topVertex.x, component.settingsComponent.triangleRight.topVertex.y),
        Vector2(component.settingsComponent.triangleRight.bottomLeftVertex.x, component.settingsComponent.triangleRight.bottomLeftVertex.y),
        Vector2(component.settingsComponent.triangleRight.bottomRightVertex.x, component.settingsComponent.triangleRight.bottomRightVertex.y), Gui::RenderColor::getColorFromGame(component.settingsComponent.triangleRight.color));
}

void Gui::RenderMenu::render(const GameData &gameData)
{
    ClearBackground(LIGHTGRAY);

    this->stateGame = gameData.dataMenu.stateGame;

    if (gameData.dataMenu.cursorState == SELECTIONNED) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
    } else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    for (auto &item: gameData.dataMenu.componentList) {
        renderOneComponent(item);
    }

    // this->drawModel((Gui::ModelInfo){0,
    //     {0, 0, 0},
    //     {0, 0, 0},
    //     0,
    //     {1, 1, 1},
    //     WHITE}
    // );
}
