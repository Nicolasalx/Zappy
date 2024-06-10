/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "RenderMenu.hpp"
#include "RenderColor.hpp"

Gui::RenderMenu::RenderMenu()
{

}

void Gui::RenderMenu::resize(int window_width, int window_height)
{
    // ! Manipulate rectangle
    // for (auto &component: this->_componentList) {
    //     component.box.x = window_width * component.stockStartData.box.x;
    //     component.box.y = window_height * component.stockStartData.box.y;
    //     component.box.width = window_width * component.stockStartData.box.width;
    //     component.box.height = window_height * component.stockStartData.box.height;

    //     component.text.pos = { window_width * component.stockStartData.text.pos.x, window_height * component.stockStartData.text.pos.y };
    // }
}

void Gui::RenderMenu::renderOneComponent(Gui::Component &component)
{
    // ! Don't create another rectangle each time
    Rectangle rectangle = {component.box.x, component.box.y, component.box.width, component.box.height};

    DrawRectangleLinesEx(rectangle, 3, Gui::RenderColor::getColorFromGame(component.box.color));
    DrawText(component.text.contentText.c_str(), component.box.x, component.box.y, 20, Gui::RenderColor::getColorFromGame(component.box.color));
}

void Gui::RenderMenu::render(const GameData &gameData)
{
    // ! Don't clear and fill componentList each time (make a pool)

        this->_componentList.clear();
    for (const auto &data: gameData.dataMenu.componentList) {
        this->_componentList.push_back(data);
    }
    for (auto &item: this->_componentList) {
        renderOneComponent(item);
    }
}
