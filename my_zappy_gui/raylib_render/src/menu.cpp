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
#include <complex>

Gui::RenderMenu::RenderMenu()
{
    this->addModel(Gui::EARTH_MODEL.data(), Gui::EARTH_TEXTURE.data());
    this->addModel(Gui::EARTH_MODEL.data(), Gui::CLOUD_TEXTURE.data());
    Image image = LoadImage(Gui::MENU_ISLAND.data());
    menuIsland = LoadTextureFromImage(image);
    UnloadImage(image);
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

void Gui::RenderMenu::render3DModel(Camera3D camera)
{
    BeginMode3D(camera);
    this->drawModel((Gui::ModelInfo){0,
        {float(1.4 + std::cos(earthRotation / 2.0) / 100.0), 9.75, float(0.7 - std::cos(earthRotation / 2.0) / 100.0)},
        {0, 1, 0},
        earthRotation,
        {1, 1, 1},
        WHITE}
    );
    this->drawModel((Gui::ModelInfo){1,
        {float(1.4 + std::cos(earthRotation / 2.0) / 100.0), 9.77, float(0.7 - std::cos(earthRotation / 2.0) / 100.0)},
        {0, 1, 0},
        earthRotation * 0.8f,
        {1.015, 1.015, 1.015},
        WHITE}
    );
    EndMode3D();
    earthRotation += 0.03;
    DrawTextureEx(menuIsland, (Vector2){650, 350 + std::cos(earthRotation / 3.0f) * 10}, 0, 0.65, WHITE);
}

void Gui::RenderMenu::render(const GameData &gameData)
{
    this->stateGame = gameData.dataMenu.stateGame;

    if (gameData.dataMenu.cursorState == SELECTIONNED) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
    } else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    for (auto &item: gameData.dataMenu.componentList) {
        renderOneComponent(item);
    }
}

void Gui::RenderMenu::renderMenu(const GameData &gameData, Camera3D camera)
{
    ClearBackground(BLACK);
    render3DModel(camera);
    render(gameData);
}

// if (gameData.infoWindow.resolution.width != window.windowSize.width || gameData.infoWindow.resolution.height != window.windowSize.height) {
//     window.windowSize.width = gameData.infoWindow.resolution.width;
//     window.windowSize.height = gameData.infoWindow.resolution.height;
//     this->needToResize = true;
//     //EndDrawing();
//     //CloseWindow();
//     //InitWindow(window.windowSize.width, window.windowSize.height, "Zappy GUI");
//     //BeginDrawing();
//     return;
// }