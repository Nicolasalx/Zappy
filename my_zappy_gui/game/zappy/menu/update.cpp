/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updateMenu
*/

#include "Menu.hpp"

bool Gui::Menu::isMouseOnBox(const Box &box, const Pos &mousePos)
{
    float boxLeft = box.x;
    float boxRight = box.x + box.width;
    float boxTop = box.y;
    float boxBottom = box.y + box.height;

    if (mousePos.x >= boxLeft && mousePos.x <= boxRight &&
        mousePos.y >= boxTop && mousePos.y <= boxBottom) {
        return true;
    } else {
        return false;
    }
}

void Gui::Menu::handleEvent(const Gui::Event &event)
{
    for (const auto &component: this->_gameData->dataMenu.componentList) {
        if (isMouseOnBox(component.box, event.mouse)) {
            std::cout << "MOUSE ON BOX\n";
        }
    }
}

void Gui::Menu::update(const Gui::Event &event)
{
    handleEvent(event);

    for (auto &component: this->_gameData->dataMenu.componentList) {
        component.box.x = event.windowSize.width * component.stockStartData.box.x;
        component.box.y = event.windowSize.height * component.stockStartData.box.y;
        component.box.width = event.windowSize.width * component.stockStartData.box.width;
        component.box.height = event.windowSize.height * component.stockStartData.box.height;

        component.text.pos = { event.windowSize.width * component.stockStartData.text.pos.x, event.windowSize.height * component.stockStartData.text.pos.y };
    }
}
