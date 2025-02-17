/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** addElement
*/

#include "Menu.hpp"
#include "GameConfig.hpp"

void Gui::Menu::addBox(const Box &box, const std::string &contentText)
{
    this->_component.stockStartData.box = box;
    this->_component.box = { box.x, box.y, box.width, box.height, box.color };
    this->_component.stockStartData.box = this->_component.box;

    double startTextPosX = (box.width - (contentText.size() * 0.02)) / 2;
    addText(Text{.contentText = contentText, .pos = { box.x + (float) startTextPosX , box.y + 0.03f }, .realPos = {0.1, 0.1}, .fontSize = sizeFontTextMenu, .color = WHITE_COLOR});
}

void Gui::Menu::addText(const Text &text)
{
    this->_component.text = text;
    this->_component.stockStartData.text = text;
}

void Gui::Menu::addTriangle(Pos startPosTriangleLeft, ComponentType cmpType)
{
    Triangle triangleLeft;

    triangleLeft.topVertex = startPosTriangleLeft;

    triangleLeft.bottomLeftVertex.x = triangleLeft.topVertex.x + 0.05;
    triangleLeft.bottomLeftVertex.y = triangleLeft.topVertex.y + 0.05;

    triangleLeft.bottomRightVertex.x = triangleLeft.topVertex.x + 0.05;
    triangleLeft.bottomRightVertex.y = triangleLeft.topVertex.y - 0.05;

    Triangle triangleRight;

    startPosTriangleLeft.x += 0.5;

    triangleRight.topVertex = startPosTriangleLeft;

    triangleRight.bottomLeftVertex.x = triangleRight.topVertex.x - 0.05;
    triangleRight.bottomLeftVertex.y = triangleRight.topVertex.y - 0.05;

    triangleRight.bottomRightVertex.x = triangleRight.topVertex.x - 0.05;
    triangleRight.bottomRightVertex.y = triangleRight.topVertex.y + 0.05;

    this->_component.settingsComponent.triangleLeft = triangleLeft;
    this->_component.settingsComponent.triangleRight = triangleRight;

    this->_component.stockStartData.settingsComponent.triangleLeft = triangleLeft;
    this->_component.stockStartData.settingsComponent.triangleRight = triangleRight;

    this->_component.settingsComponent.triangleLeft.color = BLUE_COLOR;
    this->_component.settingsComponent.triangleRight.color = BLUE_COLOR;

    if (cmpType == MODIFY_VOLUME) {
        addText(Text{.contentText = std::to_string(this->_gameData->infoWindow.volume) + " %", .pos = {0.6, 0.57}, .realPos = {0.6, 0.57}, .fontSize = 0.1, .color = WHITE_COLOR});
    } else {
        addText(Text{.contentText = _dataResolution.at(0).resText, .pos = {0.53, 0.36}, .realPos = {0.53, 0.36}, .fontSize = 0.1, .color = WHITE_COLOR});
    }
}

void Gui::Menu::addComponent(ComponentType cmpType)
{
    this->_component.componentType = cmpType;
    this->_gameData->dataMenu.componentList.push_back(_component);
    this->_component.componentType = NONE;

    this->_component = Component();
}
