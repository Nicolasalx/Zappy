/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "RenderMenu.hpp"
#include "RenderWindow.hpp"
#include "RenderColor.hpp"

Gui::RenderMenu::RenderMenu()
{

}

void Gui::RenderMenu::resize(int window_width, int window_height)
{
    for (auto &component: this->_componentList) {
        component.box.x = window_width * component.stockStartData.box.x;
        component.box.y = window_height * component.stockStartData.box.y;
        component.box.width = window_width * component.stockStartData.box.width;
        component.box.height = window_height * component.stockStartData.box.height;

        component.text.pos = { window_width * component.stockStartData.text.pos.x, window_height * component.stockStartData.text.pos.y };
    }
}

void Gui::RenderMenu::renderOneComponent(Gui::Component &component)
{
    DrawRectangleLinesEx((Rectangle) {component.box.x, component.box.y, component.box.width, component.box.height}, 3, Gui::RenderColor::getColorFromGame(component.box.color));
    DrawText(component.text.contentText.c_str(), component.box.x, component.box.y, 20, Gui::RenderColor::getColorFromGame(component.box.color));
}

void Gui::RenderMenu::initMenu(const GameData &gameData)
{
    static bool menuIsInit = false;

    if (!menuIsInit) {
        for (const auto &data: gameData.dataMenu.componentList) {
            this->_componentList.push_back(data);
        }
        menuIsInit = true;
    }
}

void Gui::RenderMenu::render(const GameData &gameData)
{
    // ! To change with width and height in Window when Ulysse will push
    this->_windowWidth = GetScreenWidth();
    this->_windowHeight = GetScreenHeight();

    ClearBackground(LIGHTGRAY);
    initMenu(gameData);
    WindowSize sizeWindow = Gui::RenderWindow::getWindowSize();
    this->_windowWidth = sizeWindow.width;
    this->_windowHeight = sizeWindow.height;

    resize(this->_windowWidth, this->_windowHeight);
    for (auto &item: this->_componentList) {
        renderOneComponent(item);
    }
}
