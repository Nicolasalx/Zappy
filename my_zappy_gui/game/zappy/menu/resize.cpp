/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** resize
*/

#include "Menu.hpp"

Gui::Pos Gui::Menu::resizePosition(const Pos position, const Gui::Event &event)
{
    Pos newPosition;

    newPosition.x = event.windowSize.width * position.x;
    newPosition.y = event.windowSize.height * position.y;
    return newPosition;
}

void Gui::Menu::resize(const Gui::Event &event)
{
    for (auto &component: this->_gameData->dataMenu.componentList) {
        component.box.x = event.windowSize.width * component.stockStartData.box.x;
        component.box.y = event.windowSize.height * component.stockStartData.box.y;
        component.box.width = event.windowSize.width * component.stockStartData.box.width;
        component.box.height = event.windowSize.height * component.stockStartData.box.height;

        component.text.pos = resizePosition(component.stockStartData.text.pos, event);
        component.text.fontSize = event.windowSize.height * component.stockStartData.text.fontSize;

        component.settingsComponent.triangleLeft.topVertex = resizePosition(component.stockStartData.settingsComponent.triangleLeft.topVertex, event);
        component.settingsComponent.triangleLeft.bottomLeftVertex = resizePosition(component.stockStartData.settingsComponent.triangleLeft.bottomLeftVertex, event);
        component.settingsComponent.triangleLeft.bottomRightVertex = resizePosition(component.stockStartData.settingsComponent.triangleLeft.bottomRightVertex, event);

        component.settingsComponent.triangleRight.topVertex = resizePosition(component.stockStartData.settingsComponent.triangleRight.topVertex, event);
        component.settingsComponent.triangleRight.bottomLeftVertex = resizePosition(component.stockStartData.settingsComponent.triangleRight.bottomLeftVertex, event);
        component.settingsComponent.triangleRight.bottomRightVertex = resizePosition(component.stockStartData.settingsComponent.triangleRight.bottomRightVertex, event);
    }
    for (auto &text: this->_gameData->dataMenu.componentsTitle) {
        text.pos = { event.windowSize.width * text.realPos.x, event.windowSize.height * text.realPos.y };
    }
}