/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "menu.hpp"

void Gui::Menu::addBox(const InfoBox &infoBox, Color color)
{
    this->_component.box = { infoBox.x, infoBox.y, infoBox.width, infoBox.height, color };
    this->_component.infoCmp.infoBox = infoBox;
}

void Gui::Menu::addText(const Text &text)
{
    this->_component.text = text;
}

void Gui::Menu::addComponent(ComponentType cmpType)
{
    this->_component.cmpType = cmpType;
    this->_componentList.push_back(_component);
    this->_component.cmpType = NONE;
}
