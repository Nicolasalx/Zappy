/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** addElement
*/

#include "Menu.hpp"

void Gui::Menu::addBox(const Box &box)
{
    this->_component.stockStartData.box = box;
    this->_component.box = { box.x, box.y, box.width, box.height, box.color };
    this->_component.stockStartData.box = this->_component.box;
}

void Gui::Menu::addText(const Text &text)
{
    this->_component.text = text;
}

void Gui::Menu::addComponent(ComponentType cmpType)
{
    this->_component.componentType = cmpType;
    this->_gameData->dataMenu.componentList.push_back(_component);
    this->_component.componentType = NONE;
}
