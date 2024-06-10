/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** resize
*/

#include "Menu.hpp"

void Gui::Menu::resize(const Gui::Event &event)
{
    for (auto &component: this->_gameData->dataMenu.componentList) {
        component.box.x = event.windowSize.width * component.stockStartData.box.x;
        component.box.y = event.windowSize.height * component.stockStartData.box.y;
        component.box.width = event.windowSize.width * component.stockStartData.box.width;
        component.box.height = event.windowSize.height * component.stockStartData.box.height;

        component.text.pos = { event.windowSize.width * component.stockStartData.text.pos.x, event.windowSize.height * component.stockStartData.text.pos.y };
    }
}