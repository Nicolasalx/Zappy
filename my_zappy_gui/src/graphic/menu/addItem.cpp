/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "menu.hpp"

void Gui::Menu::addBox(const InfoBox &infoBox, Color color)
{
    Box box;

    box.box = { infoBox.x, infoBox.y, infoBox.width, infoBox.height };
    box.color = color;
    this->_component.boxes.push_back(box);
}

void Gui::Menu::addText(const Text &text)
{
    this->_component.texts.push_back(text);
}

void Gui::Menu::addComponent(ComponentType cmpType)
{
    this->_component.cmpType = cmpType;
    this->_componentList.push_back(_component);
    this->_component.boxes.clear();
    this->_component.texts.clear();
    this->_component.cmpType = NONE;
}
