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
    Image image2 = LoadImage(Gui::SPACE_TEXTURE.data());
    spaceTexture = LoadTextureFromImage(image2);
    Image image3 = LoadImage(Gui::ZAPPY_LOGO.data());
    zappyLogo = LoadTextureFromImage(image3);

    UnloadImage(image);
    UnloadImage(image2);
    UnloadImage(image3);
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
    DrawTextureEx(spaceTexture, (Vector2){0, 0}, 0, 0.35f, WHITE);
    DrawTextureEx(zappyLogo, (Vector2){1250, 70}, 0, 0.8f, WHITE);
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
    this->inputSelect = gameData.dataMenu.inputSelect;

    if (gameData.dataMenu.cursorState == SELECTIONNED && gameData.dataMenu.stateGame == IN_MENU) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
    } else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    if (gameData.infoWindow.resolution != _optionResolution) {
        ToggleFullscreen();
        _optionResolution = gameData.infoWindow.resolution;
    }
    for (auto &item: gameData.dataMenu.componentList) {
        renderOneComponent(item);
    }
    for (auto &text: gameData.dataMenu.componentsTitle) {
        DrawText(text.contentText.c_str(), text.pos.x, text.pos.y, text.fontSize, Gui::RenderColor::getColorFromGame(text.color));
    }
}

void Gui::RenderMenu::renderMenu(const GameData &gameData, Camera3D camera)
{
    ClearBackground(BLACK);
    render3DModel(camera);
    render(gameData);
}
